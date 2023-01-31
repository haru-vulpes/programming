#include <stdio.h>
#include <stdbool.h>

bool all_div3(int array[], size_t size)
{

// pas besoin de mettre d'accolades si il n'y a qu'une ligne.

	for (size_t i = 0; i < size ; i++)
		if (array[i] % 3 != 0)
			return false;
	return true;
}

int main(void)
{
	int array[] = { 9 , 21 , 69 , 42 , 162 };

// appel de fonction dans le if directement car c'est une booléenne qui retourne vrai ou faux.

	if (all_div3(array, 5))
		printf("True\n");
	else
		printf("False\n");

	return 0;
}
