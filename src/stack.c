#include <stack.h>
#include <vector.h>

#include <stdlib.h>

struct stack_t
{
    vector_t *vector;
};

stack_t * stack_create(void)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    if (stack) {
        stack->vector = vector_create();

        if (!stack->vector) {
            free(stack);

            return NULL;
        }
    }

    return stack;
}

void stack_destroy(stack_t *stack)
{
    vector_destroy(stack->vector);

    free(stack);
}

unsigned int stack_size(const stack_t *stack)
{
    return vector_size(stack->vector);
}

int stack_push(stack_t *stack, const void *data)
{
    return vector_push_back(stack->vector, data);
}

int stack_pop(stack_t *stack, void **data)
{
    if (data) {
        *data = vector_back(stack->vector);
    }
    else {
        vector_back(stack->vector);
    }

    return vector_pop_back(stack->vector);
}