#include <queue.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 4096

static void test()
{
    queue_t *queue = queue_create();

    assert(queue_empty(queue) == true);

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        unsigned int *data = (unsigned int *)malloc(sizeof(unsigned int));

        assert(data != NULL);

        *data = index;

        queue_push(queue, data);
    }

    assert(queue_empty(queue) == false);
    assert(queue_size(queue) == TEST_SIZE);

    unsigned int index = 0;

    while (!queue_empty(queue)) {
        unsigned int *data = (unsigned int *)queue_pop(queue);

        assert(data != NULL);
        assert(*data == index);

        free(data);

        ++index;
    }

    assert(queue_empty(queue) == true);
    assert(queue_size(queue) == 0);

    queue_destroy(queue);

    printf("[\033[32mOK\033[m]\n");
}

int main(/*int argc, char *argv[]*/)
{
    test();

    return 0;
}