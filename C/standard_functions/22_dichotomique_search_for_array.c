#include <stdio.h>

int index_finder(int value, int array[], size_t size)
{
	int g = 0;
	int d = size-1;
	//[g;d] 
	size_t i = (size-1)/2;

	while(g <= d)
	{
		if (array[i] == value)
			return i;
		if (array[i] < value)
			g = i+1;
		else
			d = i-1;
		i = g+(d-g)/2;
	}
	return -1;	

}
int main()
{
        int array[] = { 0 , 12 , 23 , 43 , 54 , 65 , 76 , 87 , 98 , 99 , 100 };
        int value;
        printf("Enter a value.\n");
        scanf("%d", &value);
        int index = index_finder(value, array, 11);
        printf("The index of this value is the index %d\n", index);

        return 0;
}
