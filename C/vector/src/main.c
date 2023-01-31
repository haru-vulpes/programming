#include <stdio.h>

#include "vector.h"

int main(void)
{
    struct vector *v = vector_new();

    for (size_t i = 0; i < 20; i++)
    {
        vector_push(v, i);
        printf("Size: %zu, Capacity: %zu\n", v->size, v->capacity);
    }

    vector_destroy(v);
}
