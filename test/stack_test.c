#include <stack.h>
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 16

static void dump(stack_t *stack)
{
    printf("Stack => [");

    const unsigned int size = stack_size(stack);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = stack_at(stack, index);

        printf("%s\"%s\"", delimiter, (const char *)element);
    }

    printf("]\n");
}

static void test()
{
    stack_t *stack = stack_create();

    for (unsigned int index = 0; index < TEST_SIZE; ++index) {
        stack_push(stack, int2string(index));
    }

    assert(stack_size(stack) == TEST_SIZE);

    dump(stack);

    const char *search = "3";

    void *element = stack_find(stack, (void *)search);

    assert(!element);

    element = stack_find_if(stack, (void *)search, equal);

    assert(element);

    element = stack_find_if(stack, (void *)search, NULL);

    assert(!element);

    char *last_element = (char *)stack_back(stack);

    assert(atoi(last_element) == TEST_SIZE - 1);

    stack_pop(stack);

    free(last_element);

    assert(stack_size(stack) == (TEST_SIZE - 1));

    while (stack_size(stack)) {
        char *element = (char *)stack_back(stack);

        stack_pop(stack);

        free(element);
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