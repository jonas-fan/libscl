#include <vector.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 4096

static inline void iterator(unsigned int index, const void *data, void *user_data __attribute__((unused)))
{
    assert(data != NULL);
    assert(*((unsigned int *)data) == index);
}

static inline int compare(const void *data, const void *search, void *user_data __attribute__((unused)))
{
    assert(data != NULL);

    if (*((unsigned int *)data) == *((unsigned int *)search)) {
        return 0;
    }

    return -1;
}

static void test()
{
    vector_t *vector = vector_create();

    assert(vector_empty(vector) == true);

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        unsigned int *data = (unsigned int *)malloc(sizeof(unsigned int));

        assert(data != NULL);

        *data = index;

        vector_push_back(vector, data);
    }

    assert(vector_empty(vector) == false);
    assert(vector_size(vector) == TEST_SIZE);

    vector_for_each(vector, iterator, NULL);

    unsigned int search = TEST_SIZE >> 1;

    assert(vector_find(vector, &search) < 0);
    assert(vector_find_if(vector, &search, compare, NULL) >= 0);

    unsigned int index = TEST_SIZE - 1;

    while (!vector_empty(vector)) {
        unsigned int *data = (unsigned int *)vector_back(vector);

        assert(data != NULL);
        assert(*data == index);

        vector_pop_back(vector);

        free(data);

        --index;
    }

    assert(vector_empty(vector) == true);
    assert(vector_size(vector) == 0);

    vector_destroy(vector);

    printf("[\033[32mOK\033[m]\n");
}

int main(/*int argc, char *argv[]*/)
{
    test();

    return 0;
}