#include <stdio.h>

void to_upper(char str[])
{
	for (int i = 0; str[i] ; i++)
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
}

int main(int argc, char *argv[])
{
	to_upper(argv[1]);
	printf("%s\n", argv[1]);
	return 0;
}
