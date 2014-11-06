#include <list.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 10
#define MAX_BUFFER_SIZE 64

bool equal(void *item, void *element)
{
    const char *lhs = (const char *)item;
    const char *rhs = (const char *)element;

    return !strcasecmp(lhs, rhs);
}

void dump(List *list)
{
    printf("List => [");

    const unsigned int size = list_size(list);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = list_at(list, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n");
}

char * int2string(int number)
{
    char buffer[MAX_BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "%d", number);

    return strdup(buffer);
}

void test()
{
    List *list = list_create();

    unsigned int index;

    for (index = 0; index < TEST_SIZE; ++index) {
        list_push_back(list, int2string(index));
    }

    assert(list_size(list) == TEST_SIZE);

    dump(list);

    const char *search = "3";

    void *element = list_find(list, (void *)search);

    assert(!element);

    element = list_find_if(list, (void *)search, equal);

    assert(element);

    element = list_find_if(list, (void *)search, NULL);

    assert(!element);

    char *last_element = (char *)list_back(list);

    assert(atoi(last_element) == (TEST_SIZE - 1));

    free(last_element);

    list_pop_back(list);

    assert(list_size(list) == (TEST_SIZE - 1));

    while (list_size(list)) {
        char *element = (char *)list_back(list);

        free(element);

        list_pop_back(list);
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