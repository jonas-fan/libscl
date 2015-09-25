#include <queue.h>
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 16

static void dump(queue_t *queue)
{
    printf("Queue => [");

    const unsigned int size = queue_size(queue);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = queue_at(queue, index);

        printf("%s\"%s\"", delimiter, (const char *)element);
    }

    printf("]\n");
}

static void test()
{
    queue_t *queue = queue_create();

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        queue_push(queue, int2string(index));
    }

    assert(queue_size(queue) == TEST_SIZE);

    dump(queue);

    const char *search = "3";

    void *element = queue_find(queue, (void *)search);

    assert(!element);

    element = queue_find_if(queue, (void *)search, equal);

    assert(element);

    element = queue_find_if(queue, (void *)search, NULL);

    assert(!element);

    char *first_element = (char *)queue_front(queue);

    assert(atoi(first_element) == 0);

    queue_pop(queue);

    free(first_element);

    assert(queue_size(queue) == (TEST_SIZE - 1));

    while (queue_size(queue)) {
        char *element = (char *)queue_front(queue);

        queue_pop(queue);

        free(element);
    }

    assert(queue_size(queue) == 0);

    queue_destroy(queue);

    printf("[\033[32mOK\033[m]\n");
}

int main(const int argc, const char *argv[])
{
    test();

    return 0;
}