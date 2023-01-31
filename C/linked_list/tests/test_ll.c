#include <cgreen/cgreen.h>

#include "ll.h"

Describe(ll);

BeforeEach(ll) {}
AfterEach(ll) {}

/*Ensure (ll, has_been_created)//////////////////////////////
{
   struct ll *ll = new_ll(); 
   destroy_ll(ll);
}*/

Ensure (ll, append_when_ll_is_empty)
{
    struct ll *ll = new_ll();

    append_ll(ll, 42);

    assert_that(ll->head->data, is_equal_to(42));
    assert_that(ll->head->next, is_null);
    assert_that(ll->tail, is_equal_to(ll->head));
    destroy_ll(ll);
}

Ensure (ll, append_when_ll_has_already_one_element)
{
    struct ll *ll = new_ll();
    append_ll(ll, 1);

    append_ll(ll, 2);

    assert_that(ll->head->data, is_equal_to(1));
    assert_that(ll->head->next, is_equal_to(ll->tail));
    assert_that(ll->tail->data, is_equal_to(2));
    assert_that(ll->tail->next, is_null);
    destroy_ll(ll);
}

Ensure (ll, append_when_ll_has_already_two_element)
{
    struct ll *ll = new_ll();
    append_ll(ll, 1);
    append_ll(ll, 2);
    struct knot *old_tail = ll->tail;

    append_ll(ll, 3);

    assert_that(old_tail->data, is_equal_to(2));
    assert_that(old_tail->next, is_equal_to(ll->tail));
    assert_that(ll->tail->data, is_equal_to(3));
    assert_that(ll->tail->next, is_null);
    destroy_ll(ll);
}

Ensure (ll, size_is_3)
{
    struct ll *ll = new_ll();

    append_ll(ll, 1);
    append_ll(ll, 2);
    append_ll(ll, 3);

    assert_that(ll_size(ll), is_equal_to(3));
    destroy_ll(ll);
}

Ensure (ll, size_rec_is_3)
{
    struct ll *ll = new_ll();

    append_ll(ll, 1);
    append_ll(ll, 2);
    append_ll(ll, 3);

    assert_that(ll_size_rec(ll), is_equal_to(3));
    destroy_ll(ll);
}

Ensure (ll, sum_of_data)
{
	struct ll *ll = new_ll();

	for (size_t i = 0; i < 10; i++)
		append_ll(ll, i);

	assert_that(sum_of_data(ll), is_equal_to(45));

	destroy_ll(ll);
}

Ensure (ll, product_of_data)
{
	struct ll *ll = new_ll();

	for (size_t i = 1; i < 10; i++)
		append_ll(ll, i);

	print(ll->head);
	assert_that(product_of_data(ll), is_equal_to(362880));

	destroy_ll(ll);
}
