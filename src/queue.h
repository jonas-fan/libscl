#ifndef __LIBSCL_QUEUE_H__
#define __LIBSCL_QUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif

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

#endif  /* __LIBSCL_QUEUE_H__ */