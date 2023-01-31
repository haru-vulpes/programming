#include <stdio.h>
#include <stdlib.h>

void array_sorter(int array[],size_t size)
{       
        int save = 0;
	int reset = 0;
	int i = 0;

	while (i < size)
	{
		if (array[i] != array[size-1])
			if (array[i] > array[i+1])
			{
				save = array[i];
				array[i] = array[i+1];
				array[i+1] = save;
				reset++;
			}

		if (i == size-1)
			if (reset > 0)
			{
				reset = 0;
				i = -1;
			}

		i++;
	}		
}

int main(int argc, char *argv[]){
	
	int size = argc-1;
	int array[size];
	
	for (int i = 0; i < size; i++)
		array[i] = atoi(argv[i+1]);

	array_sorter(array, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", array[i]);

	return 0;
}
