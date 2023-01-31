#include <cgreen/cgreen.h>

#include "queue.h"

static struct token make_token(int a)
{
	struct token token = {.type = NUMBER, .value = a};
	return token;
}

Describe(queue);
BeforeEach(queue) {}
AfterEach(queue) {}
Ensure(queue, fifo)
{
	struct queue *queue = new_queue();
	push_front(queue, make_token(1));
	push_front(queue, make_token(2));
	assert_that(pop_back(queue).value, is_equal_to(1));
	assert_that(pop_back(queue).value, is_equal_to(2));
	destroy_queue(queue);
}
Ensure(queue, fifo2)
{
	struct queue *queue = new_queue();
	push_back(queue, make_token(1));
	push_back(queue, make_token(2));
	assert_that(pop_front(queue).value, is_equal_to(1));
	assert_that(pop_front(queue).value, is_equal_to(2));
	destroy_queue(queue);
}
Ensure(queue, lifo)
{
	struct queue *queue = new_queue();
	push_back(queue, make_token(1));
	push_back(queue, make_token(2));
	push_back(queue, make_token(3));
	push_back(queue, make_token(4));
	assert_that(pop_back(queue).value, is_equal_to(4));
	assert_that(pop_back(queue).value, is_equal_to(3));
	assert_that(pop_back(queue).value, is_equal_to(2));
	assert_that(pop_back(queue).value, is_equal_to(1));
	destroy_queue(queue);
}
Ensure(queue, fifo_lifo_etc)
{
	struct queue *queue = new_queue();
	push_back(queue, make_token(1));
	push_front(queue, make_token(2));
	push_back(queue, make_token(3));
	push_back(queue, make_token(4));
	push_front(queue, make_token(5));
	push_back(queue, make_token(6));
	push_front(queue, make_token(7));
	push_back(queue, make_token(8));
	push_back(queue, make_token(9));
	push_front(queue, make_token(0));
	assert_that(pop_back(queue).value, is_equal_to(9));
	assert_that(pop_front(queue).value, is_equal_to(0));
	assert_that(pop_back(queue).value, is_equal_to(8));
	assert_that(pop_back(queue).value, is_equal_to(6));
	assert_that(pop_front(queue).value, is_equal_to(7));
	assert_that(pop_front(queue).value, is_equal_to(5));
	assert_that(pop_front(queue).value, is_equal_to(2));
	assert_that(pop_front(queue).value, is_equal_to(1));
	assert_that(pop_back(queue).value, is_equal_to(4));
	assert_that(pop_back(queue).value, is_equal_to(3));
	destroy_queue(queue);
}
Ensure(queue, destroy)
{
	struct queue *queue = new_queue();
	push_back(queue, make_token(1));
	push_back(queue, make_token(2));
	push_back(queue, make_token(3));
	push_back(queue, make_token(4));
	destroy_queue(queue);
}
