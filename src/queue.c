#include <queue.h>


/**
 *    Public methods
 */

queue_t * queue_create(void)
{
    return list_create();
}

void queue_destroy(queue_t *queue)
{
    list_destroy(queue);
}

unsigned int queue_size(const queue_t *queue)
{
    return list_size(queue);
}

void * queue_at(const queue_t *queue, unsigned int index)
{
    return list_at(queue, index);
}

void * queue_front(const queue_t *queue)
{
    return list_front(queue);
}

void * queue_back(const queue_t *queue)
{
    return list_back(queue);
}

int queue_push(queue_t *queue, const void *data)
{
    return list_push_back(queue, data);
}

int queue_pop(queue_t *queue)
{
    return list_pop_front(queue);
}

void * queue_find(const queue_t *queue, const void *data)
{
    return list_find(queue, data);
}

void * queue_find_if(const queue_t *queue,
                     const void *data,
                     int (*compare)(const void *element, const void *data))
{
    return list_find_if(queue, data, compare);
}