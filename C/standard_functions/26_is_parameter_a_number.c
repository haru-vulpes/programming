#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

	////////////////
	//    CORE    //
	////////////////

//is_digit est une copie de isdigit dans la lib standart qu'on appel avec ctype.h

bool is_digit(char c)
{
        return c >= '0' && c <= '9';
}

bool is_number(char str[])
{
        for (size_t i = 0; str[i]; i++)
                if (!isdigit(str[i]))
                        return false;
        return true;
}
	
	/////////////
	//  INFRA  //
	/////////////

int main (int argc, char *argv[])
{
	if (argc != 2)
		return 1;

	if (is_number(argv[1]))
		printf("It's a number.\n");
	else 
		printf("It's not a number.\n");

	return 0;
}
