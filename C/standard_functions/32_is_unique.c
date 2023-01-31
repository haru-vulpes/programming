#include <stdio.h>
#include <stdbool.h>

/*

bool isitunique(char str[])
{
	for (size_t i = 0; str[i]; i++)
		for (size_t j = i+1; str[j]; j++)
		{
			if (str[i] == str[j])
				return false;
		}
	return true;
}

*/

bool isitunique_v2(char str[])
{
	int array[128] = { 0 }; // { 0 } <=> toutes les cases à zero

	for(size_t i = 0; str[i]; i++)
		array[str[i]]++;

	for(size_t i = 0; i < 128; i++)
		if (array[i] > 1)
			return false;	
	return true;
}

void test(char str[], int expected_return);

int main(int argc, char *argv[])
{
	test("azertyy", 0); 
	test("azerty", 1); 
	test("ouinon", 0); 
        test("      ",0);	
	test("   non",0);
	test("oui  ",0);
	test("O U I",0);
	test("O oAaZze", 1);
	test("salut chewie", 1);

	return 0;
}

void test(char str[], int expected_return)
{
	if (isitunique_v2(str) == expected_return)
		printf("OK\n");
	else
		printf("NOT OK, return %d, expected %d\n", isitunique_v2(str), expected_return);
}


