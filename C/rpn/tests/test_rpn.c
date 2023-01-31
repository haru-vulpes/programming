#include <cgreen/cgreen.h>

#include "queue.h"
#include "lexer.h"
#include "rpn.h"

Describe(rpn);

BeforeEach(rpn) {}
AfterEach(rpn) {}

Ensure(rpn, return_the_result_of_an_addition)
{
    struct queue *input = queue_lexed("42 58 +");
    double n = rpn_eval(input);

    assert_that_double(n, is_equal_to_double(100));
	destroy_queue(input);
}
Ensure(rpn, return_the_result_of_an_difference)
{
    struct queue *input = queue_lexed("58 42 -");
    double n = rpn_eval(input);

    assert_that_double(n, is_equal_to_double(-16));
	destroy_queue(input);
}
Ensure(rpn, return_the_result_of_a_product)
{
    struct queue *input = queue_lexed("6 7 *");
    double n = rpn_eval(input);

    assert_that_double(n, is_equal_to_double(42));
	destroy_queue(input);
}
Ensure(rpn, return_the_result_of_an_operation_complexe)
{
    struct queue *input = queue_lexed("1 3 2 3 5 * 7 - / * +");
    double n = rpn_eval(input);

    assert_that_double(n, is_equal_to_double(-11));
	destroy_queue(input);
}
