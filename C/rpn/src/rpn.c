#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "rpn.h"

void handle_operator(struct queue *stack, struct token token)
{
	double rhs = pop_front(stack).value;
	double lhs = pop_front(stack).value;
	struct token value;
	value.type = NUMBER;
	if (token.type == PLUS)
		value.value = rhs + lhs;
	if (token.type == MINUS)
		value.value = rhs - lhs;
	if (token.type == PROD)
		value.value = rhs * lhs;
	if (token.type == DIV)
		value.value = rhs / lhs;
	push_front(stack, value);
}

double rpn_eval(struct queue *input)
{
	double value;
	struct token token;
	struct queue *stack = new_queue();
	while (!is_empty(input))
	{
		token = pop_back(input);
		if (token.type == NUMBER)
			push_front(stack, token);
		else 
			handle_operator(stack, token);
	}
	value = pop_front(stack).value;
	destroy_queue(stack);
    return value;
}
