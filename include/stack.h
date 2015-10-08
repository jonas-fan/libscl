#ifndef SIMPLE_CONTAINER_STACK_H_
#define SIMPLE_CONTAINER_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Stack (Vector based)
 *
 *    @date    2015/10/08
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct stack_t stack_t;

stack_t * stack_create(void);
void stack_destroy(stack_t *stack);

unsigned int stack_size(const stack_t *stack);

int stack_push(stack_t *stack, const void *data);
int stack_pop(stack_t *stack, void **data);

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_STACK_H_ */