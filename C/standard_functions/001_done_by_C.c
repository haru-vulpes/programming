#include <stdio.h>
#include <stdbool.h>
 
int sum_of_words(const char str[])
{
	if (!str[0])
		return -1;

	int result = 0;
	for (size_t i = 0; str[i]; i++)
		result += str[i];

	return result;
}

bool is_prime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

void test_sum_of_words(const char str[], int expected)
{
	// GIVEN

	// WHEN
	int result = sum_of_words(str);

	// THEN
	if (result == expected)
		printf("sum: %s: OK\n", str);
	else
		printf("sum: %s: KO. Expected %d, but got %d\n",
				str, expected, result);
}

void test_is_prime(int n, bool expected)
{
	// GIVEN

	// WHEN
	bool result = is_prime(n);

	// THEN
	if (result == expected)
		printf("is_prime: %d: OK\n", n);
	else
		printf("is_prime: %d: KO. Expected %d, but got %d\n",
				n, expected, result);
}

void run_tests(void)
{
	test_sum_of_words("", -1);
	test_sum_of_words("A", 65);
	test_sum_of_words("AB", 131);

	test_is_prime(2, true);
	test_is_prime(1, false);
	test_is_prime(4, false);
	test_is_prime(17, true);
	test_is_prime(18, false);
}

void show_prime_message(const char word[], bool is_prime)
{
	if (is_prime)
		printf("%s is a prime word.\n", word);
	else
		printf("%s is not a prime word.\n", word);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		run_tests();
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		int sum = sum_of_words(argv[i]);
		bool prime = is_prime(sum);
		show_prime_message(argv[i], prime);
	}
	return 0;
}
