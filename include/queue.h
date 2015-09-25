#ifndef SIMPLE_CONTAINER_QUEUE_H_
#define SIMPLE_CONTAINER_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <list.h>

/**
 *    Simple Queue (List based)
 *
 *    @version 0.1.1
 *    @date    2015/03/13
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef list_t queue_t;

typedef queue_t Queue;

Queue * queue_create(void);
void queue_destroy(Queue *queue);

unsigned int queue_size(const Queue *queue);

void * queue_at(const Queue *queue, unsigned int index);
void * queue_front(const Queue *queue);
void * queue_back(const Queue *queue);

void queue_push(Queue *queue, const void *data);
void queue_pop(Queue *queue);

void * queue_find(const Queue *queue, const void *item);
void * queue_find_if(const Queue *queue,
                     const void *item,
                     bool (*predicate)(const void *item, const void *element));

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_QUEUE_H_ */