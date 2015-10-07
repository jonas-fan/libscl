#include <list.h>
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 4096

static inline void iterator(unsigned int index, void *data, unsigned int data_size, void *user_data)
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
    list_t *list = list_create();

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        list_push_back(list, &index, sizeof(index));
    }

    assert(list_size(list) == TEST_SIZE);

    list_for_each(list, iterator, NULL);

    int search = TEST_SIZE + 1;
    assert(list_find(list, &search, sizeof(search)) < 0);

    search = TEST_SIZE >> 1;
    assert(list_find(list, &search, sizeof(search)) == search);

    search = TEST_SIZE >> 3;
    assert(list_find_if(list, &search, sizeof(search), compare) == search);

    unsigned int data;
    list_back(list, &data, sizeof(data));
    assert(data == (TEST_SIZE - 1));

    list_pop_front(list);
    assert(list_size(list) == (TEST_SIZE - 1));

    list_destroy(list);

    printf("[\033[32mOK\033[m]\n");
}

int main(/*int argc, char *argv[]*/)
{
    test();

    return 0;
}
