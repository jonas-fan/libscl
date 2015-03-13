#include <list.h>
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 10

static void dump(List *list)
{
    printf("List => [");

    const unsigned int size = list_size(list);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = list_at(list, index);

        printf("%s\"%s\"", delimiter, (const char *)element);
    }

    printf("]\n");
}

static void test()
{
    List *list = list_create();

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        list_push_back(list, int2string(index));
    }

    assert(list_size(list) == TEST_SIZE);

    dump(list);

    const char *search = "3";

    void *element = list_find(list, search);

    assert(!element);

    element = list_find_if(list, search, equal);

    assert(element);

    element = list_find_if(list, search, NULL);

    assert(!element);

    char *last_element = (char *)list_back(list);

    assert(atoi(last_element) == (TEST_SIZE - 1));

    list_pop_back(list);

    free(last_element);

    assert(list_size(list) == (TEST_SIZE - 1));

    while (list_size(list)) {
        char *element = (char *)list_back(list);

        list_pop_back(list);

        free(element);
    }

    assert(list_size(list) == 0);

    list_destroy(list);

    printf("[\033[32mOK\033[m]\n");
}

int main(const int argc, const char *argv[])
{
    test();

    return 0;
}