#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////

///////////////
// CORE CODE //
///////////////

int str_occ_count(char str[], char substr[])
{
	int j = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (substr[j] == str[i])
		{
			j++;	
			if (substr[j] == '\0')
				return j;	
		}
	}
	return -1;
}

int str_str(char str[], char substr[])
{
	int result = 0;
	int j = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (substr[j] == str[i])
		{
			j++;	
			result = i+1;
			if (substr[j] == '\0')
				return result-j;	
			else if(substr[j] != str[i+1])
				j = 0;
		}
	}
	return -1;
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////
// TEST CODE DECLARATION/PROTOTYPE //
/////////////////////////////////////

void test_code(int expresult, char str[], char substr[]);

/////////////////////////////////////////////////////////////////////////////

//////////////////////
// INFRA CODE / MAIN//
//////////////////////

int main (int argc, char *argv[])
{

	////////////////
	// CODE INFRA //
	////////////////

	if (str_str(argv[1], argv[2]) == -1)
		printf("There's no occurences.\n");
	else
	{
		printf("Occurence start index. %d\n", str_str(argv[1], argv[2]));	
		printf("There is %d similar words.\n", str_occ_count(argv[1], argv[2]));
	}

	///////////////
	// CODE TEST //
	///////////////

	printf("\n***************TESTS*****************\n");	

	test_code(21,"i am not maria, i am mario", "mario"); // close words
	test_code(-1,"",""); // no words
	test_code(-1,"Sushis",""); // str without substr
	test_code(-1,"","Pizza"); // substr without str
	test_code(-1,"ori","iro"); // inversed
	test_code(-1,"i am not maria, i am mario", "polaria"); //similar words
	test_code(-1,"i am not maria, i am mario", "mario ");
	test_code(20,"i am not maria, i am mario", " mario");
	test_code(5,"maro mari","mari"); 
	test_code(-1, "il y a maria et mario", "mariamario");

	return 0;
}

/////////////////////////////////////////////////////////////////////////////

//////////////////////////
// CODE TEST DEFINITION //
//////////////////////////

void test_code(int expresult, char str[], char substr[])
{
	int expected_result = expresult;
	int actual_result = str_str(str, substr);
	
	if (expected_result == actual_result)
	    printf("OK\n");
	else
	    printf("KO: expected %d, got %d\n", expected_result, actual_result);
}
