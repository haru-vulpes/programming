#include <stdio.h>

int a_to_i(char str[])
{
        int result = 0;
	size_t i;
	int sign;

	if (str[0] == '-')
	{
		i = 1;
		sign = -1;
	}
	else
	{
		i = 0;
		sign = 1;
	}

	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}

int main(int argc, char *argv[])
{
        printf("%d\n", a_to_i(argv[1]));

        return 0;
}
