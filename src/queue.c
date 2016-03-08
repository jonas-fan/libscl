#include <queue.h>
#include <list.h>

#include <stdlib.h>

struct queue_t
{
    list_t *list;
};

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

bool queue_empty(queue_t *queue)
{
    return list_empty(queue->list);
}

unsigned int queue_size(queue_t *queue)
{
    return list_size(queue->list);
}

int queue_push(queue_t *queue, const void *data)
{
    return list_push_back(queue->list, data);
}

void * queue_pop(queue_t *queue)
{
    void *data = list_front(queue->list);

    list_pop_front(queue->list);

    return data;
}