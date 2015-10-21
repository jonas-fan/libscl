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

unsigned int stack_size(const stack_t *stack)
{
    return list_size(stack->list);
}

int stack_push(stack_t *stack, const void *data, unsigned int data_size)
{
    return list_push_back(stack->list, data, data_size);
}

int stack_pop(stack_t *stack, void *data, unsigned int data_size)
{
    list_back(stack->list, data, data_size);

    return list_pop_back(stack->list);
}