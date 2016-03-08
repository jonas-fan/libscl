#include <stack.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 4096

static void test()
{
    stack_t *stack = stack_create();

    assert(stack_empty(stack) == true);

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        unsigned int *data = (unsigned int *)malloc(sizeof(unsigned int));

        assert(data != NULL);

        *data = index;

        stack_push(stack, data);
    }

    assert(stack_empty(stack) == false);
    assert(stack_size(stack) == TEST_SIZE);

    unsigned int index = TEST_SIZE - 1;

    while (!stack_empty(stack)) {
        unsigned int *data = (unsigned int *)stack_pop(stack);

        assert(data != NULL);
        assert(*data == index);

        free(data);

        --index;
    }

    assert(stack_empty(stack) == true);
    assert(stack_size(stack) == 0);

    stack_destroy(stack);

    printf("[\033[32mOK\033[m]\n");
}

int main(/*int argc, char *argv[]*/)
{
    test();

    return 0;
}