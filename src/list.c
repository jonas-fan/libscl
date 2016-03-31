#include <list.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct list_node_t list_node_t;

struct list_node_t
{
    void *data;
    list_node_t *previous;
    list_node_t *next;
};

struct list_t
{
    unsigned int size;
    list_node_t *head;
    list_node_t *tail;
};

static inline list_node_t * list_node_create(const void *data)
{
    list_node_t *node = (list_node_t *)malloc(sizeof(list_node_t));

    if (node) {
        memset(node, 0, sizeof(list_node_t));

        node->data = (void *)data;
    }

    return node;
}

static inline void list_node_destroy(list_node_t *node)
{
    free(node);
}

static inline list_node_t * list_at_(list_t *list, unsigned int index)
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

list_t * list_create(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (list) {
        memset(list, 0, sizeof(list_t));
    }

    return list;
}

void list_destroy(list_t *list)
{
    list_node_t *node = list->head;

    while (node) {
        list_node_t *next = node->next;

        list_node_destroy(node);

        node = next;
    }

    free(list);
}

bool list_empty(list_t *list)
{
    return !list->size;
}

unsigned int list_size(list_t *list)
{
    return list->size;
}

void * list_at(list_t *list, unsigned int index)
{
    const list_node_t *node = list_at_(list, index);

    if (!node) {
        return NULL;
    }

    return node->data;
}

void * list_front(list_t *list)
{
    if (!list->head) {
        return NULL;
    }

    return list->head->data;
}

void * list_back(list_t *list)
{
    if (!list->tail) {
        return NULL;
    }

    return list->tail->data;
}

int list_insert(list_t *list, unsigned int index, const void *data)
{
    list_node_t *node = list_at_(list, index);

    if (!node) {
        return -1;
    }

    list_node_t *new_node = list_node_create(data);

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

    list_node_destroy(node);

    return 0;
}

int list_push_front(list_t *list, const void *data)
{
    list_node_t *node = list_node_create(data);

    if (!node) {
        return -1;
    }

    if (list->head) {
        node->next = list->head;
        list->head->previous = node;
        list->head = node;
    }
    else {
        list->head = node;
        list->tail = node;
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

    list_node_destroy(node);

    return 0;
}

int list_push_back(list_t *list, const void *data)
{
    list_node_t *node = list_node_create(data);

    if (!node) {
        return -1;
    }

    if (list->tail) {
        node->previous = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else {
        list->head = node;
        list->tail = node;
    }

    ++list->size;

    return 0;
}

int list_pop_back(list_t *list)
{
    if (!list->size) {
        return -1;
    }

    list_node_t *node = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = node->previous;
        list->tail->next = NULL;
    }

    --list->size;

    list_node_destroy(node);

    return 0;
}

void list_for_each(list_t *list,
                   void (*callback)(unsigned index, const void *data, void *user_data),
                   void *user_data)
{
    if (!callback) {
        return;
    }

    unsigned int index = 0;

    list_node_t *node = list->head;

    while (node) {
        callback(index, node->data, user_data);

        node = node->next;

        ++index;
    }
}

void list_for_each_reverse(list_t *list,
                           void (*callback)(unsigned int index, const void *data, void *user_data),
                           void *user_data)
{
    if (!callback) {
        return;
    }

    unsigned int index = list->size - 1;

    list_node_t *node = list->tail;

    while (node) {
        callback(index, node->data, user_data);

        node = node->previous;

        --index;
    }
}

void list_reverse(list_t *list)
{
    if (list->head == list->tail) {
        return;
    }

    list_node_t *node = list->head;

    while (node) {
        list_node_t *previous = node->previous;

        node->previous = node->next;
        node->next = previous;

        node = node->previous;
    }

    node = list->head;
    list->head = list->tail;
    list->tail = node;
}

int list_find(list_t *list, const void *search)
{
    int index = 0;

    list_node_t *node = list->head;

    while (node && (node->data != search)) {
        node = node->next;

        ++index;
    }

    return (node)?  index : -1;
}

int list_find_if(list_t *list,
                 const void *search,
                 int (*compare)(const void *data, const void *search, void *user_data),
                 void *user_data)
{
    if (!compare) {
        return -1;
    }

    int index = 0;

    list_node_t *node = list->head;

    while (node && compare(node->data, search, user_data)) {
        node = node->next;

        ++index;
    }

    return (node)?  index : -1;
}