#include <stdio.h>
#include <stdbool.h>

bool array_sorted(int array[], size_t size)
{
	for (size_t i = 0; i < size-1; i++)
		if (array[i] > array[i+1])
			return false;
		return true;
}	

int main()
{
	int array[] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 };
	bool result = array_sorted(array, 7);

	if (result)
		printf("The array is sorted.\n");
	else
		printf("The array is not sorted.\n");

	return 0; /*le return 0; du main veut dire "je me suis conclue sans erreur"*/
}
