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

/* initialize the list */
void list_init(struct list *list);

/* check to see if the list is empty */
int list_empty(struct list *list);

/* return the first entry of the list */
struct list_entry * list_front(struct list *list);

/* return the last entry of the list */
struct list_entry * list_back(struct list *list);

/* insert an element into the list, return the entry pointing to the element */
struct list_entry * list_insert(struct list *list, struct list_entry *postion,
    const void *data);

/* remove the entry from the list, return next entry */
struct list_entry * list_erase(struct list *list, struct list_entry *entry);

/* add an element at the begining of the list, return 1 on success, 0 otherwise */
int list_push_front(struct list *list, const void *data);

/* add an element at the end of the list, return 1 on success, 0 otherwise */
int list_push_back(struct list *list, const void *data);

/* remove the first entry of the list */
void list_pop_front(struct list *list);

/* remove the last entry of the list */
void list_pop_back(struct list *list);

/* traverse the list */
#define list_for_each(list, entry) \
    for (entry = (list)->head; \
         entry; \
         entry = ((entry)->next == (list)->head) ? NULL : (entry)->next)

/* traverse the list in reverse order */
#define list_for_each_reverse(list, entry) \
    for (entry = (list)->head ? (list)->head->previous : NULL; \
         entry; \
         entry = ((entry)->previous == (list)->head->previous) ? NULL : (entry)->previous)

#ifdef __cplusplus
}
#endif

#endif /* __LIBSIMPLECNTR_LIST_H__ */