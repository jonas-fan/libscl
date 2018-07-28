#ifndef __LIBSIMPLECNTR_LIST_H__
#define __LIBSIMPLECNTR_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

struct list_entry
{
    struct list_entry *previous;
    struct list_entry *next;
    void *data;
};

struct list
{
    struct list_entry *head;
};

void list_entry_init(struct list_entry *entry, void *data);

void list_init(struct list *list);

int list_empty(struct list *list);

void list_insert(struct list *list, struct list_entry *postion,
    struct list_entry *entry);

void list_erase(struct list *list, struct list_entry *entry);

void list_push_front(struct list *list, struct list_entry *entry);

void list_push_back(struct list *list, struct list_entry *entry);

void list_pop_front(struct list *list);

void list_pop_back(struct list *list);

#define list_for_each(list, entry) \
    for (entry = (list)->head; \
         entry; \
         entry = ((entry)->next == (list)->head) ? NULL : (entry)->next)

#define list_for_each_reverse(list, entry) \
    for (entry = (list)->head ? (list)->head->previous : NULL; \
         entry; \
         entry = ((entry)->previous == (list)->head->previous) ? NULL : (entry)->previous)

#ifdef __cplusplus
}
#endif

#endif /* __LIBSIMPLECNTR_LIST_H__ */