#include "list.h"

#include <stddef.h>

void list_entry_init(struct list_entry *entry, void *data)
{
    entry->previous = entry;
    entry->next = entry;
    entry->data = data;
}

void list_init(struct list *list)
{
    list->head = NULL;
}

int list_empty(struct list *list)
{
    return (list->head == NULL);
}

void list_insert(struct list *list, struct list_entry *position,
    struct list_entry *entry)
{
    struct list_entry **indirect = (!position || position == list->head) ?
        &list->head : &position;

    if (*indirect) {
        entry->previous = (*indirect)->previous;
        entry->next = *indirect;
        (*indirect)->previous->next = entry;
        (*indirect)->previous = entry;
    }

    *indirect = entry;   
}

void list_erase(struct list *list, struct list_entry *entry)
{
    entry->previous->next = entry->next;
    entry->next->previous = entry->previous;

    if (entry == list->head) {
        list->head = (entry->next == list->head) ? NULL : entry->next;
    }

    entry->previous = entry;
    entry->next = entry;
}

void list_push_front(struct list *list, struct list_entry *entry)
{
    list_insert(list, list->head, entry);
}

void list_push_back(struct list *list, struct list_entry *entry)
{
    list_insert(list, list->head, entry);
    list->head = list->head->next;
}

void list_pop_front(struct list *list)
{
    if (!list_empty(list)) {
        list_erase(list, list->head);
    }
}

void list_pop_back(struct list *list)
{
    if (!list_empty(list)) {
        list->head = list->head->next;
        list_erase(list, list->head);
    }
}