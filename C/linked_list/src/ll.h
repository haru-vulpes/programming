#pragma once

// STRUCT /////////////////////

struct knot
{
    int data;
    struct knot *next;
};

struct ll
{
    struct knot *head;
    struct knot *tail;
};

////////////////////////////

struct ll *new_ll(void);

void append_ll(struct ll *ll, int elem);

void destroy_ll(struct ll *ll);

void prepend_ll(struct ll *ll, int elem);

size_t ll_size(const struct ll *ll);

int sum_of_data(struct ll *ll);

size_t ll_size_rec(const struct ll *ll);

int product_of_data(struct ll *ll);

void print(const struct knot *knot);
