#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lexer.h"
#include "queue.h"

static struct token token_from_str(char *str)
{
	struct token token;
	token.value = NAN;
	if (str[0] == '+')
		token.type = PLUS;
	else if (str[0] == '-')
		token.type = MINUS;
	else if (str[0] == '*')
		token.type = PROD;
	else if (str[0] == '/')
		token.type = DIV;
	else if (str[0] == '(')
		token.type = OPENPAR;
	else if (str[0] == ')')
		token.type = CLOSEPAR;
	else
	{
		token.type = NUMBER;
		token.value = strtod(str, NULL);
	}
	return token;
}
struct queue *queue_lexed(char *input)
{
	struct queue *queue = new_queue();
	char *str = strdup(input);
	char *saveptr;
	for (char *tmp_str = str; ; tmp_str = NULL)
	{
		char *token_str = strtok_r(tmp_str, " ", &saveptr);
		if (token_str == NULL)
			break;
		struct token token = token_from_str(token_str);
		push_front(queue, token);
	}
	free(str);
	return queue;
}
