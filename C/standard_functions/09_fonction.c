#include <stdio.h>

int main () {

	//////////////////////////////////////////////////
	//fonction returning the addition of two numbers//
	//////////////////////////////////////////////////

	int addition(int num1, int num2) {
	
	//////////////////////////////
	//local variable declaration//
	//////////////////////////////

		int result;

		result = num1 + num2;

		return result;
	}

	int a;
	int b;
	int c;
	
	printf("entrez une première valeure\n");
	scanf("%d", &a);
	printf("entrez une deuxième valeure\n");
	scanf("%d", &b);

	////////////////////
	//fonction calling//
	////////////////////

	c = addition(a,b);
	printf("Addition is %d\n",c);
	
	return 0;
}
