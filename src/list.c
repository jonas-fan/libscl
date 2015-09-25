#include <list.h>

#include <stdlib.h>
#include <string.h>


/**
 *    Private
 */

typedef struct list_node_t list_node_t;

struct list_node_t
{
    const void *data;
    list_node_t *previous;
    list_node_t *next;
};

struct list_t
{
    unsigned int size;
    list_node_t *head;
    list_node_t *tail;
};

static inline list_node_t * list_element_create(const void *data)
{
    list_node_t *node = (list_node_t *)malloc(sizeof(list_node_t));

    if (node) {
        memset(node, 0, sizeof(*node));

        node->data = data;
    }

    return node;
}

static inline void list_element_destroy(list_node_t *node)
{
    free(node);
}

static inline list_node_t * list_at_(const list_t *list, unsigned int index)
{
    if (index >= list->size) {
        return NULL;
    }

    list_node_t *node = list->head;

    while (index--) {
        node = node->next;
    }

    return node;
}


/**
 *    Public methods
 */

list_t * list_create(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (list) {
        memset(list, 0, sizeof(*list));
    }

    return list;
}

void list_destroy(list_t *list)
{
    list_node_t *node = list->head;

    while (node) {
        list_node_t *next = node->next;

        list_element_destroy(node);

        node = next;
    }

    free(list);
}

unsigned int list_size(const list_t *list)
{
    return list->size;
}

void * list_at(const list_t *list, unsigned int index)
{
    const list_node_t *node = list_at_(list, index);

    return (node)?  (void *)node->data : NULL;
}

void * list_front(const list_t *list)
{
    return (void *)list->head->data;
}

void * list_back(const list_t *list)
{
    return (void *)list->tail->data;
}

int list_insert(list_t *list, unsigned int index, const void *data)
{
    list_node_t *node = list_at_(list, index);

    if (!node) {
        return -1;
    }

    list_node_t *new_node = list_element_create(data);

    if (!new_node) {
        return -1;
    }

    new_node->next = node;
    new_node->previous = node->previous;

    if (list->head == node) {
        list->head = new_node;
    }
    else {
        node->previous->next = new_node;
    }

    node->previous = new_node;

    ++list->size;

    return 0;
}

int list_erase(list_t *list, unsigned int index)
{
    list_node_t *node = list_at_(list, index);

    if (!node) {
        return -1;
    }

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else if (node == list->head) {
        node->next->previous = NULL;
        list->head = node->next;
    }
    else if (node == list->tail) {
        node->previous->next = NULL;
        list->tail = node->previous;
    }
    else {
        node->next->previous = node->previous;
        node->previous->next = node->next;
    }

    --list->size;

    list_element_destroy(node);

    return 0;
}

int list_push_front(list_t *list, const void *data)
{
    list_node_t *new_node = list_element_create(data);

    if (!new_node) {
        return -1;
    }

    if (list->head) {
        new_node->next = list->head;
        list->head->previous = new_node;
        list->head = new_node;
    }
    else {
        list->head = new_node;
        list->tail = new_node;
    }

    ++list->size;

    return 0;
}

int list_pop_front(list_t *list)
{
    if (!list->size) {
        return -1;
    }

    list_node_t *node = list->head;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = node->next;
        list->head->previous = NULL;
    }

    --list->size;

    list_element_destroy(node);

    return 0;
}

int list_push_back(list_t *list, const void *data)
{
    list_node_t *new_node = list_element_create(data);

    if (!new_node) {
        return -1;
    }

    if (list->tail) {
        new_node->previous = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else {
        list->head = new_node;
        list->tail = new_node;
    }

    ++list->size;

    return 0;
}

int list_pop_back(list_t *list)
{
    if (!list->size) {
        return -1;
    }

    list_node_t *element = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = element->previous;
        list->tail->next = NULL;
    }

    --list->size;

    list_element_destroy(element);

    return 0;
}

void * list_find(const list_t *list, const void *data)
{
    list_node_t *node = list->head;

    while (node && (node->data != data)) {
        node = node->next;
    }

    return (node)?  (void *)node->data : NULL;
}

void * list_find_if(const list_t *list,
                    const void *data,
                    int (*compare)(const void *element, const void *data))
{
    if (!compare) {
        return NULL;
    }

    list_node_t *node = list->head;

    while (node && compare(node->data, data)) {
        node = node->next;
    }

    return (node)?  (void *)node->data : NULL;
}