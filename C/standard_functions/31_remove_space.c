#define _GNU_SOURCE
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void remove_spaces(char str[])
{
	for (size_t i = 0; str[i]; i++)
		if (str[i] == ' ')
		{
			for (size_t j = i; str[j]; j++)
				str[j] = str[j+1];
			i--;
		}
}

void check_remove_spaces(char input[], char expected[]);

int main(int argc, char *argv[]) 
{
	check_remove_spaces("j'aime pas les espaces","j'aimepaslesespaces");
	check_remove_spaces("         ","");
	check_remove_spaces("  j'aime  ","j'aime");
	check_remove_spaces(" j'aime ","j'aime");
	check_remove_spaces(" j ' a i m e ","j'aime");
	check_remove_spaces("j'  aim    e","j'aime");
	check_remove_spaces("j'ai jamais  vue    de       phrase aussi l o n g u e",
			"j'aijamaisvuedephraseaussilongue");
	check_remove_spaces("sérieux?","sérieux?");
	check_remove_spaces("aaaaaa  ","aaaaaa");

	return 0;
}

void check_remove_spaces(char input[], char expected[])
{
	char *copy = strdup(input);
 
	remove_spaces(copy);
 
	if (!strcmp(copy, expected))
		printf("OK\n");
	else
		printf("KO: expected %s, got %s\n", expected, copy);
 
	free(copy);
}

/*
   /!\ Code des tenebres, à ne pas reproduire, danger /!\ :

 void remove_spaces(char str[])
{
        for (size_t i = 0; str[i]; i++)
                if (str[i] == 32)
                        if (str[i+1] != 32)
                        {
                                str[i] = str[i+1];

                                if (str[i] == '\0')
                                        if (str[i-1] == 32)
                                        {
                                                str[i-1] = '\0';
                                                remove_spaces(str);
                                        }
                                        else
                                                str[i] = '\0';
                                else
                                {
                                        str[i+1] = 32;
                                        remove_spaces(str);
                                }
                        }
}
*/
