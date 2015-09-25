#include <stack.h>


/**
 *    Public methods
 */

stack_t * stack_create(void)
{
    return vector_create();
}

void stack_destroy(stack_t *stack)
{
    vector_destroy(stack);
}

unsigned int stack_size(const stack_t *stack)
{
    return vector_size(stack);
}

void * stack_at(const stack_t *stack, unsigned int index)
{
    return vector_at(stack, index);
}

void * stack_front(const stack_t *stack)
{
    return vector_front(stack);
}

void * stack_back(const stack_t *stack)
{
    return vector_back(stack);
}

int stack_push(stack_t *stack, const void *data)
{
    return vector_push_back(stack, data);
}

int stack_pop(stack_t *stack)
{
    return vector_pop_back(stack);
}

void * stack_find(const stack_t *stack, const void *data)
{
    return vector_find(stack, data);
}

void * stack_find_if(const stack_t *stack,
                     const void *data,
                     int (*comapre)(const void *element, const void *data))
{
    return vector_find_if(stack, data, comapre);
}