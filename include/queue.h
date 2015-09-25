#ifndef SIMPLE_CONTAINER_QUEUE_H_
#define SIMPLE_CONTAINER_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <list.h>

/**
 *    Queue (List based)
 *
 *    @date    2015/09/25
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef list_t queue_t;

queue_t * queue_create(void);
void queue_destroy(queue_t *queue);

unsigned int queue_size(const queue_t *queue);

void * queue_at(const queue_t *queue, unsigned int index);
void * queue_front(const queue_t *queue);
void * queue_back(const queue_t *queue);

int queue_push(queue_t *queue, const void *data);
int queue_pop(queue_t *queue);

void * queue_find(const queue_t *queue, const void *data);
void * queue_find_if(const queue_t *queue,
                     const void *data,
                     int (*compare)(const void *element, const void *data));

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_QUEUE_H_ */