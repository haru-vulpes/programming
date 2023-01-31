#include "vector.h"

#include <stdlib.h>

struct vector *vector_new(void)
{
    struct vector *v = malloc(sizeof(*v)); // DEREF PAS POUR DE VRAI TKT
    // SAME AS
    //struct vector *v = malloc(sizeof(struct vector));

    v->data = NULL;
    v->size= 0;
    v->capacity = 0;

    return v;
}

void vector_destroy(struct vector *vector)
{
    if (vector)
        free(vector->data);
    free(vector);
}

void vector_push(struct vector *vector, int elem)
{
    vector->size += 1; 
    if (vector->capacity < vector->size)
    {
        vector->capacity = vector->size * 2;
        *vector = realloc(*vector, vector->capacity * sizeof(*vector));
    }
    vector->data[vector->size-1] = elem;
}

/*int vector_pop(struct vector *vector)
{
}
*/
