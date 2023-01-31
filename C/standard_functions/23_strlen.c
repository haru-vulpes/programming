#include <stdio.h>

int stlen(char mystring[])
{
	int compt = 0;

	for (int i = 0; mystring[i] != '\0'; i++)
		compt++;
	return compt;
}

int main()
{
	char mystring[] = "coucou"; /* char mystring[] = "coucou" <=> char mystring [] = { 'c', 'o', 'u', 'c', 'o', 'u', '\0' }; */
	printf("number of elements : %d\n", stlen(mystring));
	return 0;
}
