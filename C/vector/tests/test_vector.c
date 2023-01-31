#include <cgreen/cgreen.h>

#include "vector.h"
// DO NOT DO THIS
//#include "../src/vector.h" // BERK CACA

// Deux grands trucs à lire sur le TDD
// Uncle Bob: c'est un nazi, règles hyper strictes
// Kent Beck: plus relax sur les règles
// http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd

// SUT : System Under Test
Describe(vector);

// Things that will be executed before and after each test
BeforeEach(vector) {}
AfterEach(vector) {}

Ensure(vector, has_a_size_0_after_creation)
{
    // GIVEN

    // WHEN
    struct vector *v = vector_new();

    // THEN
    //assert(v->size == 0); // TDD style, old school, but works
    assert_that(v->size, is_equal_to(0)); // BDD style, looks like english

    vector_destroy(v);
}
