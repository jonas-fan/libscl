#ifndef SIMPLE_CONTAINER_STACK_H_
#define SIMPLE_CONTAINER_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <vector.h>

/**
 *    Stack (Vector based)
 *
 *    @date    2015/09/25
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef vector_t stack_t;

stack_t * stack_create(void);
void stack_destroy(stack_t *stack);

unsigned int stack_size(const stack_t *stack);

void * stack_at(const stack_t *stack, unsigned int index);
void * stack_front(const stack_t *stack);
void * stack_back(const stack_t *stack);

int stack_push(stack_t *stack, const void *data);
int stack_pop(stack_t *stack);

void * stack_find(const stack_t *stack, const void *data);
void * stack_find_if(const stack_t *stack,
                     const void *data,
                     int (*compare)(const void *element, const void *data));

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_STACK_H_ */