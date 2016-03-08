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
        queue_push(queue, &index, sizeof(index));
    }

    assert(queue_empty(queue) == false);
    assert(queue_size(queue) == TEST_SIZE);

    unsigned int index = 0;
    unsigned int data;

    while (!queue_empty(queue)) {
        queue_pop(queue, &data, sizeof(data));

        assert(data == index);

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