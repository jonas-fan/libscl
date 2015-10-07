#ifndef SIMPLE_CONTAINER_QUEUE_H_
#define SIMPLE_CONTAINER_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Queue (List based)
 *
 *    @date    2015/10/07
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct queue_t queue_t;

queue_t * queue_create(void);
void queue_destroy(queue_t *queue);

unsigned int queue_size(const queue_t *queue);

int queue_push(queue_t *queue, const void *data, unsigned data_size);
int queue_pop(queue_t *queue, void *data, unsigned data_size);

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_QUEUE_H_ */