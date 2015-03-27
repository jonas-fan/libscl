#ifndef SIMPLE_CONTAINER_STACK_H_
#define SIMPLE_CONTAINER_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <vector.h>

/**
 *    Simple Stack (Vector based)
 *
 *    @version 0.1.0
 *    @date    2015/03/27
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef Vector stack_t;

typedef stack_t Stack;

Stack * stack_create(void);
void stack_destroy(Stack *stack);

unsigned int stack_size(const Stack *stack);

void * stack_at(const Stack *stack, unsigned int index);
void * stack_front(const Stack *stack);
void * stack_back(const Stack *stack);

void stack_push(Stack *stack, const void *data);
void stack_pop(Stack *stack);

void * stack_find(const Stack *stack, const void *item);
void * stack_find_if(const Stack *stack,
                     const void *item,
                     bool (*predicate)(const void *item, const void *element));

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_STACK_H_ */