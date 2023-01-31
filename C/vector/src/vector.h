#include <stddef.h>

struct vector
{
    int *data;
    size_t size; // Number of elements in data
    size_t capacity; // What realloc gave me, may be bigger than size
};

struct vector *vector_new(void);

void vector_destroy(struct vector *vector);

// Also called vector_push in some languages
void vector_push(struct vector *vector, int elem);

// Can be useful if you see the vector as a "stack"
//int vector_pop(struct vector *vector);
