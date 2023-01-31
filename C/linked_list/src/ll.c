#include <stdlib.h>
#include <stdio.h>

#include "ll.h"

struct ll *new_ll(void)
{
	struct ll *new_ll = malloc(sizeof(struct ll));
	new_ll->head = NULL;
	new_ll->tail = NULL;

	return new_ll;
}
void append_ll(struct ll *ll, int elem)
{
	if (ll->head != NULL)
	{
		struct knot *new_knot = malloc(sizeof(struct knot));
		new_knot->data = elem;
		new_knot->next = NULL;
		ll->tail->next = new_knot;
		ll->tail = new_knot;
	}
	else
	{
		struct knot *new_knot = malloc(sizeof(struct knot));
		new_knot->data = elem;
		new_knot->next = NULL;

		ll->head = new_knot;
		ll->tail = new_knot;
	}
}
void prepend_ll(struct ll *ll, int elem)
{
	ll->tail = malloc(sizeof(struct knot));
	ll->tail->data = elem;
}
static void destroy_every_knots(struct knot *knot)
{
	if (!knot)
		return;
	destroy_every_knots(knot->next);	
	free(knot);
}
void destroy_ll(struct ll *ll)
{
	destroy_every_knots(ll->head);
	free(ll);
}
static int product_of_knots(struct knot *knot)
{
	if (!knot)
		return 1;
	return knot->data * product_of_knots(knot->next);
}
int product_of_data(struct ll *ll)
{
	return product_of_knots(ll->head);
}
static int sum_of_knot_data(struct knot *knot)
{
	if (!knot)
		return 0;
	return knot->data + sum_of_knot_data(knot->next);
}
int sum_of_data(struct ll *ll)
{
	return sum_of_knot_data(ll->head);
}
static size_t size_rec(const struct knot *knot)
{
	if (!knot)
		return 0;
	return 1 + size_rec(knot->next);
}
size_t ll_size_rec(const struct ll *ll)
{
	return size_rec(ll->head);
}
size_t ll_size(const struct ll *ll)
{
	size_t size = 0;

	for (struct knot *knot = ll->head; knot; knot = knot->next)
		size++;

	return size;
}
void print(const struct knot *knot)
{
	if (!knot)
		return;
	print(knot->next);
	printf("%d\n", knot->data);
}
