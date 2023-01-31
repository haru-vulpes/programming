#include <stdio.h>

int str_len(char array[])
{
	size_t compt = 0;

	for (size_t i = 0; array[i] != '\0'; i++)
		compt++;
	return compt;
}

int main(int argc, char *argv[])
{
	for (size_t i = 0; i < argc; i++)
		printf("\nParameter number %lu: (%s) have %i index.\n",
		i+1, argv[i], str_len(argv[i])+1);

	printf("\nThere is %d parameters in total.\n\n", argc);

	return 0;
}
