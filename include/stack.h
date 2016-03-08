#ifndef SCL_STACK_H_
#define SCL_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Stack (List based)
 *
 *    @date    2016/03/08
 *    @author  Jian <jianfan.tw@gmail.com>
 */

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

#endif  /* SCL_STACK_H_ */