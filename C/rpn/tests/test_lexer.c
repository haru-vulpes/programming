#include <cgreen/cgreen.h>

#include "lexer.h"
#include "token.h"
#include "queue.h"

Describe(lexer);

BeforeEach(lexer) {}
AfterEach(lexer) {}

Ensure(lexer, give_a_beautiful_queue)
{
	char *str = "15 * 7 - 9 / ( 800 - 5 )";

	struct queue *queue = queue_lexed(str);

	struct token token = pop_back(queue);
	assert_that(token.type, is_equal_to(NUMBER));
	assert_that_double(token.value, is_equal_to_double(15));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(PROD));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(NUMBER));
	assert_that_double(token.value, is_equal_to_double(7));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(MINUS));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(NUMBER));
	assert_that_double(token.value, is_equal_to_double(9));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(DIV));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(OPENPAR));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(NUMBER));
	assert_that_double(token.value, is_equal_to_double(800));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(MINUS));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(NUMBER));
	assert_that_double(token.value, is_equal_to_double(5));

	token = pop_back(queue);
	assert_that(token.type, is_equal_to(CLOSEPAR));

	destroy_queue(queue);
}
