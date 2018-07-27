#include "list.h"

#include <stdlib.h>
#include <string.h>

list_t * list_new(void *data)
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

int list_insert(list_t **node, void *data)
{
    list_t *newer = list_new(data);

    if (!newer) {
        return 0;
    }

    if (*node) {
        list_t *previous = (*node)->previous;

        newer->previous = previous;
        newer->next = previous->next;
        previous->next->previous = newer;
        previous->next = newer;
    }

    *node = newer;

    return 1;
}

void list_delete(list_t **head, list_t *entry)
{
    entry->next->previous = entry->previous;
    entry->previous->next = entry->next;

    if (*head == entry) {
        list_t *next = (*head)->next;
        *head = (*head == next) ? NULL : next;
    }

    free(entry);
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