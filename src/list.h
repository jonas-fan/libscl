#ifndef __LIBSCL_LIST_H__
#define __LIBSCL_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct list_t list_t;

struct list_t
{
    struct list_t *previous;
    struct list_t *next;
    void *data;
};

list_t * list_new(void *data);
void list_delete(list_t **head);
int list_insert(list_t **head, void *data);
int list_push_front(list_t **head, void *data);
int list_push_back(list_t **head, void *data);
void list_pop_front(list_t **head);
void list_pop_back(list_t **head);

#ifdef __cplusplus
}
#endif

#endif  /* __LIBSCL_LIST_H__ */