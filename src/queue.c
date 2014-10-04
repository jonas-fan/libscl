#include <queue.h>

Queue * queue_create(void)
{
    return list_create();
}

void queue_destroy(Queue *queue)
{
    list_destroy(queue);
}

unsigned int queue_size(const Queue *queue)
{
    return list_size(queue);
}

void * queue_at(const Queue *queue, unsigned int index)
{
    return list_at(queue, index);
}

void * queue_front(const Queue *queue)
{
    return list_front(queue);
}

void * queue_back(const Queue *queue)
{
    return list_back(queue);
}

void queue_push(Queue *queue, void *data)
{
    list_push_back(queue, data);
}

void queue_pop(Queue *queue)
{
    list_pop_front(queue);
}

void * queue_find(const Queue *queue, void *item)
{
    return list_find(queue, item);
}

void * queue_find_if(const Queue *queue, void *item, bool (*predicate)(void *item, void *element))
{
    return list_find_if(queue, item, predicate);
}