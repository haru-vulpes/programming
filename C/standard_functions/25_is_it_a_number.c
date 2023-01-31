#include <stdio.h>
#include <stdbool.h>

bool is_digit(char c)
{
	// ici (c >= '0' && c <= '9') est une expression, qui retourne une valeur bouléenne
	// si elle est vrai 1 si elle est fausse 0.
	
	return c >= '0' && c <= '9';
}

bool is_number(char str[])
{
	for (size_t i = 0; str[i] != '\0' ; i++)
		// "!" équivaut à un opérateur, une négation booléenne
	 	if (!is_digit(str[i]))
			return false;
	return true;
}

int main(void)
{
	char str[] = "5234";

	printf("%i\n", is_number(str));

	return 0;
}

