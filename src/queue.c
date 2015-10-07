#include <queue.h>
#include <list.h>
#include <stdlib.h>

struct queue_t
{
    list_t *list;
};


/**
 *    Public methods
 */

queue_t * queue_create(void)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

    if (queue) {
        queue->list = list_create();

        if (!queue->list) {
            free(queue);

            return NULL;
        }
    }

    return queue;
}

void queue_destroy(queue_t *queue)
{
    list_destroy(queue->list);

    free(queue);
}

unsigned int queue_size(const queue_t *queue)
{
    return list_size(queue->list);
}

int queue_push(queue_t *queue, const void *data, unsigned data_size)
{
    return list_push_back(queue->list, data, data_size);
}

int queue_pop(queue_t *queue, void *data, unsigned data_size)
{
    list_front(queue->list, data, data_size);

    return list_pop_front(queue->list);
}