#include <list.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 8

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
    list_t *list = list_create();

    assert(list_empty(list) == true);

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        unsigned int *data = (unsigned int *)malloc(sizeof(unsigned int));

        assert(data != NULL);

        *data = index;

        list_push_back(list, data);
    }

    assert(list_empty(list) == false);
    assert(list_size(list) == TEST_SIZE);

    list_reverse(list);
    list_reverse(list);

    list_for_each(list, iterator, NULL);
    list_for_each_reverse(list, iterator, NULL);

    unsigned int search = TEST_SIZE >> 1;

    assert(list_find(list, &search) < 0);
    assert(list_find_if(list, &search, compare, NULL) >= 0);

    unsigned int index = TEST_SIZE - 1;

    while (!list_empty(list)) {
        unsigned int *data = (unsigned int *)list_back(list);

        assert(data != NULL);
        assert(*data == index);

        list_pop_back(list);

        free(data);

        --index;
    }

    assert(list_empty(list) == true);
    assert(list_size(list) == 0);

    list_destroy(list);

    printf("[\033[32mOK\033[m]\n");
}

int main(/*int argc, char *argv[]*/)
{
    test();

    return 0;
}
