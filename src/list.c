#include "list.h"

#include <stdlib.h>
#include <string.h>

static inline list_t * __list_new(void *data)
{
    list_t *node = (list_t *)malloc(sizeof(list_t));

    if (node) {
        memset(node, 0, sizeof(list_t));
        node->data = data;
        node->previous = node;
        node->next = node;
    }

    return node;
}

int list_insert(list_t **position, void *data)
{
    list_t *newer = __list_new(data);

    if (newer) {
        list_t *indirect = *position;

        if (indirect) {
            newer->previous = indirect->previous;
            newer->next = indirect;
            indirect->previous->next = newer;
            indirect->previous = newer;
        }

        *position = newer;
    }

    return (*position == newer);
}

void list_delete(list_t **head, list_t *node)
{
    node->next->previous = node->previous;
    node->previous->next = node->next;

    if (*head == node) {
        list_t *next = (*head)->next;
        *head = (*head == next) ? NULL : next;
    }

    free(node);
}

int list_push_front(list_t **head, void *data)
{
    return list_insert(head, data);
}

int list_push_back(list_t **head, void *data)
{
    if (!list_insert(head, data)) {
        return 0;
    }

    *head = (*head)->next;

    return 1;
}

void list_pop_front(list_t **head)
{
    list_delete(head, *head);
}

void list_pop_back(list_t **head)
{
    list_delete(head, (*head)->previous);
}