#include <stack.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 4096

static void test()
{
    stack_t *stack = stack_create();

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        stack_push(stack, &index, sizeof(index));
    }

    assert(stack_size(stack) == TEST_SIZE);

    unsigned int index = TEST_SIZE - 1;
    unsigned int data;

    while (stack_size(stack)) {
        stack_pop(stack, &data, sizeof(data));

        assert(data == index);

        --index;
    }

    assert(stack_size(stack) == 0);

    stack_destroy(stack);

    printf("[\033[32mOK\033[m]\n");
}

int main(/*int argc, char *argv[]*/)
{
    test();

    return 0;
}