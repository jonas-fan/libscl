#ifndef __LIBSCL_STACK_H__
#define __LIBSCL_STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct stack_t stack_t;

stack_t * stack_create(void);
void stack_destroy(stack_t *stack);

bool stack_empty(stack_t *stack);
unsigned int stack_size(stack_t *stack);

int stack_push(stack_t *stack, const void *data);
void * stack_pop(stack_t *stack);

#ifdef __cplusplus
}
#endif

#endif  /* __LIBSCL_STACK_H__ */