#include <stdio.h> 

	int main () { 

	int a;

	printf("entrez un chiffre, 5: Hello, autre: Goodbye\n");
	scanf("%d", &a);

	if (a == 5){
		printf("Hello\n");
	}

	else { 
		printf("Goodbye\n");
	}

	return 0;

}
