#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b)
{
	int r = -1;
	int pgcd;
	int count = 0;

	while (r != 0)
	{
		count++;
		pgcd = r;
		r = a%b;
		a = b;
		b = r;
	}
	if (count < 2)
		return 0;
	else
		return pgcd;
}

void test(int a, int b, int expected_result);

int main(int argc, char *argv[]){

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	int rest = pgcd(num1 ,num2);

	if (rest == 1)
		printf("\nThose number are prime between them and the last rest is %d.\n\n", rest);
	else
		printf("\nNOT PRIME TOGETHER, PGCD = %d.\n\n", rest);

	printf("*****************************************\n");
	printf("********************TEST*****************\n");
	printf("*****************************************\n");

	test(65,55,5);
	test(109,98,1);
	test(42,28,14);
	test(80,6,2);
	test(210,20,10);
	test(20,8,4);
	test(80,12,4);
	test(24,16,8);
	test(18,12,6);
	test(44,33,11);
	test(40,32,8);

	return 0;
}

void test(int a, int b, int expected_result)
{
	if(last_rest(a ,b) == expected_result)
		printf("OK, expected %d, got %d.\n", expected_result, last_rest(a ,b));
	else
		printf("NOT OK, expected %d, got %d.\n", expected_result, last_rest(a, b));
}
