#ifndef C_SIMPLE_STL_QUEUE_H_
#define C_SIMPLE_STL_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <list.h>

/**
 *    Simple Queue (List based)
 *
 *    @version 0.1.0
 *    @date    2014/10/04
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef List queue_t;

typedef queue_t Queue;

Queue * queue_create(void);
void queue_destroy(Queue *queue);

unsigned int queue_size(const Queue *queue);

void * queue_at(const Queue *queue, unsigned int index);
void * queue_front(const Queue *queue);
void * queue_back(const Queue *queue);

void queue_push(Queue *queue, void *data);
void queue_pop(Queue *queue);

void * queue_find(const Queue *queue, void *item);
void * queue_find_if(const Queue *queue, void *item, bool (*predicate)(void *item, void *element));

#ifdef __cplusplus
}
#endif

#endif  /* C_SIMPLE_STL_QUEUE_H_ */