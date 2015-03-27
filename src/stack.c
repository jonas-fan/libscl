#include <stack.h>


/**
 *    Public methods
 */

Stack * stack_create(void)
{
    return vector_create();
}

void stack_destroy(Stack *stack)
{
    vector_destroy(stack);
}

unsigned int stack_size(const Stack *stack)
{
    return vector_size(stack);
}

void * stack_at(const Stack *stack, unsigned int index)
{
    return vector_at(stack, index);
}

void * stack_front(const Stack *stack)
{
    return vector_front(stack);
}

void * stack_back(const Stack *stack)
{
    return vector_back(stack);
}

void stack_push(Stack *stack, const void *data)
{
    vector_push_back(stack, data);
}

void stack_pop(Stack *stack)
{
    vector_pop_back(stack);
}

void * stack_find(const Stack *stack, const void *item)
{
    return vector_find(stack, item);
}

void * stack_find_if(const Stack *stack,
                     const void *item,
                     bool (*predicate)(const void *item, const void *element))
{
    return vector_find_if(stack, item, predicate);
}