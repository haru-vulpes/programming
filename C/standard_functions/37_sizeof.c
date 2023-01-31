#include <stdio.h>

int main()
{
	printf("sizeof(char) = %zu\n", sizeof(char));
	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(long) = %zu\n", sizeof(long));

	char str[] = "hello, world!";
	printf("sizeof(str) = %zu\n", sizeof(str));
	printf("sizeof(str[0]) = %zu\n", sizeof(str[0]));

	char *p = str;
	printf("sizeof(p) = %zu\n", sizeof(p));
	printf("sizeof(p[0]) = %zu\n", sizeof(p[0]));
	printf("sizeof(*p) = %zu\n", sizeof(*p));
	printf("sizeof(size_t) = %zu\n", sizeof(size_t));

	return 0;
}
