#include <vector.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 4096

static inline void iterator(unsigned int index, void *data, unsigned int data_size, void *user_data __attribute__((unused)))
{
    assert(memcmp(data, &index, data_size) == 0);
}

static inline int compare(const void *data, unsigned int data_size,
                          const void *search, unsigned int search_size)
{
    if (data_size != search_size) {
        return -1;
    }

    return memcmp(data, search, data_size);
}

static void test()
{
    vector_t *vector = vector_create(sizeof(unsigned int));

    assert(vector_empty(vector) == true);

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        vector_push_back(vector, &index);
    }

    assert(vector_empty(vector) == false);
    assert(vector_size(vector) == TEST_SIZE);

    vector_for_each(vector, iterator, NULL);

    int search = TEST_SIZE + 1;
    assert(vector_find(vector, &search) < 0);

    search = TEST_SIZE >> 1;
    assert(vector_find(vector, &search) == search);

    search = TEST_SIZE >> 3;
    assert(vector_find_if(vector, &search, sizeof(search), compare) == search);

    unsigned int data;
    unsigned int index = TEST_SIZE - 1;

    while (!vector_empty(vector)) {
        vector_back(vector, &data);

        assert(data == index);

        vector_pop_back(vector);

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