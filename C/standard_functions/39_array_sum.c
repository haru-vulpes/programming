#include <stdio.h>

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int *begin = arr;
int *end = arr + 10;

// Return the sum of the array from 'begin' to 'end'.
int array_sum(int *begin, int *end)
{
	int compt = 0;
	size_t size = end - begin;

	for (size_t i = 0; i != size; i++)
	{
		compt += *begin;
		begin++;
	}
	return compt;
}

int main()
{
    int sum = array_sum(begin, end);
    printf("sum = %2i\n", sum);
}

/*
 * 
int array_sum(int *begin, int *end)
{
    int compt = 0;
    for (; begin != end; begin++)
        compt += *begin;
    return compt;
}
*
*/
/*
int array_sum(int *begin, int *end)
{
        int compt = 0;
        size_t size = end - begin;

        for (size_t i = 0; i != size; i++)
                compt += *(begin + i);
        return compt;
}

