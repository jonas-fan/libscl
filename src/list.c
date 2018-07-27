#include "list.h"

#include <stdlib.h>
#include <string.h>

static inline struct list_entry * __list_entry_init(const void *data)
{
    struct list_entry *entry = (struct list_entry *)malloc(sizeof(struct list_entry));

    if (entry) {
        memset(entry, 0, sizeof(struct list_entry));
        entry->previous = entry;
        entry->next = entry;
        entry->data = (void *)data;
    }

    return entry;
}

static inline void __list_entry_term(struct list_entry *entry)
{
    free(entry);
}

void list_init(struct list *list)
{
    memset(list, 0, sizeof(struct list));
}

void list_term(struct list *list)
{
    if (!list_empty(list)) {
        abort();
    }

    memset(list, 0, sizeof(struct list));
}

int list_empty(struct list *list)
{
    return (list->head == NULL);
}

struct list_entry * list_front(struct list *list)
{
    return list_empty(list) ? NULL : list->head;
}

struct list_entry * list_back(struct list *list)
{
    return list_empty(list) ? NULL : list->head->previous;
}

static inline struct list_entry * __list_insert(struct list *list,
    struct list_entry *position, struct list_entry *entry)
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

    return entry;
}

struct list_entry * list_insert(struct list *list, struct list_entry *position,
    const void *data)
{
    struct list_entry *entry = __list_entry_init(data);

    if (entry) {
        return __list_insert(list, position, entry);
    }

    return NULL;
}

struct list_entry * list_erase(struct list *list, struct list_entry *entry)
{
    struct list_entry *next = (entry == entry->next) ? NULL : entry->next;

    entry->previous->next = entry->next;
    entry->next->previous = entry->previous;

    if (entry == list->head) {
        list->head = next;
    }

    __list_entry_term(entry);

    return next;
}

int list_push_front(struct list *list, const void *data)
{
    return (list_insert(list, list->head, data) != NULL);
}

int list_push_back(struct list *list, const void *data)
{
    if (list_insert(list, list->head, data)) {
        list->head = list->head->next;
        return 1;
    }

    return 0;
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