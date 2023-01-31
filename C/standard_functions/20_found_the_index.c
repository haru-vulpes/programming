#include <stdio.h>

int index_finder(int value, int array[], size_t size)
{
	for (size_t i = 0; i < size ; i++)
		if (value == array[i])
			return i;
	return -1;
}

int main()
{
	int array[] = { 0 , 1 , 2 , 42 , 8 , 9 , 54 , 62 , 100 , 69 };
	int value;
	printf("Enter a value.\n");
	scanf("%d", &value);
	int index = index_finder(value, array, 10);
	printf("The index of this value is the index %d\n", index);

	return 0;
}
