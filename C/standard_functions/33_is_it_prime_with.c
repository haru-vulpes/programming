#include <stdio.h>
#include <stdlib.h>

// dit si premier ///////////////////////////////////////////
int pgcd(int bigger, int num)
{
        int rest = -1;
        int pgcd;
        int count = 0;

        while (rest != 0)
        {
                count++;
                pgcd = rest;
                rest = bigger%num;
                bigger = num;
                num = rest;
        }
        if (count < 2)
                return 0;
        else
                return pgcd;
}

//prend le plus gros entier ////////////////////////////////
int bigger_elem(int array[], size_t size)
{
	int bigger = 0;

	for (int i = 0; i < size; i++)	
		if (array[i] > bigger)
			bigger = array[i];
	return bigger;
}

//array_sorter /////////////////////////////////////////////
void array_sorter(int array[], size_t size)
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

void print(int array[], int bigger, size_t size);

//main /////////////////////////////////////////////////////
int main (int argc, char *argv[]) {
	
	int size = argc-1;
	int array[size];

	for (int i = 0; i < size; i++)
		array[i] = atoi(argv[i+1]);

	for (int i = 0; i < size; i++)
		if (array[i] == 0)
		{
			printf("\n   Don't put 0 among your numbers, thx\n\n");
			return 0;
		}

	int bigger = bigger_elem(array, size);
	array_sorter(array, size);
	size--;

	printf("\n Number ");
	print(array, bigger, size);
	printf("are prime with %d.\n", bigger);
	printf("\n");

	return 0;
}

//print///////////////////////////////////////////////////
void print(int array[], int bigger, size_t size)
{
	for (int i = 0; i < size; i++)
		if (pgcd(bigger, array[i]) == 1)
			printf("%d, ", array[i]);

}
