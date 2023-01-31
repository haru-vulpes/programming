#include <stdio.h>

int main() {
	float a, b, somme, produit, difference, quotient;
	
	printf("entrez deux nombres\n");
	scanf("%f%f", &a, &b);

	somme = a + b;
	
	printf("addition = %f\n", somme);

	difference = a - b;

	printf("soustraction = %f\n", difference);
	
	produit = a * b;

	printf("produit = %f\n", produit);

	quotient = a / b;

	printf("division = %f\n", quotient);

		return 0;
	}
