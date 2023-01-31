#include <stdio.h>

int stlen(char *str)
{
	int compt = 0;

        for (int i = 0; str[i] != '\0'; i++)
	        compt++;
	return compt;
}

int stlen2(char *str)
{
	int compt = 0;
	
	for (;*str != '\0';str++,compt++);

	return compt;
}

int main()
{
	char str[] = "j'adore la bite"; 

	printf("number of elements : %d\n", stlen(str));
	printf("number of elements : %d\n", stlen2(str));

	return 0;
}
