#include <stack.h>
#include <list.h>

#include <stdlib.h>

struct stack_t
{
    list_t *list;
};

stack_t * stack_create(void)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    if (stack) {
        stack->list = list_create();

        if (!stack->list) {
            free(stack);

            return NULL;
        }
    }

    return stack;
}

void stack_destroy(stack_t *stack)
{
    list_destroy(stack->list);

    free(stack);
}

bool stack_empty(stack_t *stack)
{
    return list_empty(stack->list);
}

unsigned int stack_size(stack_t *stack)
{
    return list_size(stack->list);
}

int stack_push(stack_t *stack, const void *data)
{
    return list_push_back(stack->list, data);
}

void * stack_pop(stack_t *stack)
{
    void *data = list_back(stack->list);

    list_pop_back(stack->list);

    return data;
}