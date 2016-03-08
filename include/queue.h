#ifndef SCL_QUEUE_H_
#define SCL_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Queue (List based)
 *
 *    @date    2016/03/08
 *    @author  Jian <jianfan.tw@gmail.com>
 */

#include <stdbool.h>

typedef struct queue_t queue_t;

queue_t * queue_create(void);
void queue_destroy(queue_t *queue);

bool queue_empty(queue_t *queue);
unsigned int queue_size(queue_t *queue);

int queue_push(queue_t *queue, const void *data);
void * queue_pop(queue_t *queue);

#ifdef __cplusplus
}
#endif

#endif  /* SCL_QUEUE_H_ */