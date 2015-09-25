#include <vector.h>
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 16

static void dump(vector_t *vector)
{
    printf("Vector => [");

    const unsigned int size = vector_size(vector);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = vector_at(vector, index);

        printf("%s\"%s\"", delimiter, (const char *)element);
    }

    printf("]\n");
}

static void test()
{
    vector_t *vector = vector_create();

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        vector_push_back(vector, int2string(index));
    }

    assert(vector_size(vector) == TEST_SIZE);

    dump(vector);

    const char *search = "3";

    void *element = vector_find(vector, search);

    assert(!element);

    element = vector_find_if(vector, search, equal);

    assert(element);

    element = vector_find_if(vector, search, NULL);

    assert(!element);

    char *last_element = (char *)vector_back(vector);

    assert(atoi(last_element) == (TEST_SIZE - 1));

    vector_pop_back(vector);

    free(last_element);

    assert(vector_size(vector) == (TEST_SIZE - 1));

    while (vector_size(vector)) {
        char *element = (char *)vector_back(vector);

        vector_pop_back(vector);

        free(element);
    }

    assert(vector_size(vector) == 0);

    vector_destroy(vector);

    printf("[\033[32mOK\033[m]\n");
}

int main(const int argc, const char *argv[])
{
    test();

    return 0;
}