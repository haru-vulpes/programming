#include <stdio.h>

struct array
{
	int array[20];
	size_t size;
};

int index_finder(int value, struct array array)
{
	int g = 0;
	int d = array.size-1;
	//[g;d] 
	size_t i = (array.size-1)/2;

	while(g <= d)
	{
		if (array.array[i] == value)
			return i;
		if (array.array[i] < value)
			g = i+1;
		else
			d = i-1;
		i = g+(d-g)/2;
	}
	return -1;	

}
int main()
{
	struct array array = {{ 0 , 12 , 23 , 43 , 54 , 65 , 76 , 87 , 98 , 99 , 100 }, 11};
        int value;
        printf("Enter a value.\n");
        scanf("%d", &value);
        int index = index_finder(value, array);
        printf("The index of this value is the index %d\n", index);

        return 0;
}
