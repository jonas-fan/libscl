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
int list_push_back(list_t **head, void *data);
void list_pop_back(list_t **head);
int list_push_front(list_t **head, void *data);
void list_pop_front(list_t **head);

// #include <stdbool.h>

// typedef struct list_t list_t;
// typedef struct list_node_t list_node_t;

// struct list_t
// {
//     unsigned int size;
//     list_node_t *head;
//     list_node_t *tail;
// };

// struct list_node_t
// {
//     void *data;
//     list_node_t *previous;
//     list_node_t *next;
// };

// list_t * list_create(void);
// void list_destroy(list_t *list);

// bool list_empty(const list_t *list);
// unsigned int list_size(const list_t *list);

// int list_push_front(list_t *list, const void *data);
// int list_pop_front(list_t *list);
// int list_push_back(list_t *list, const void *data);
// int list_pop_back(list_t *list);

// // void * list_at(list_t *list, unsigned int index);
// void * list_front(list_t *list);
// void * list_back(list_t *list);

// int list_push_front(list_t *list, const void *data);
// int list_pop_front(list_t *list);
// int list_push_back(list_t *list, const void *data);
// int list_pop_back(list_t *list);

// int list_insert(list_t *list, unsigned int index, const void *data);
// int list_erase(list_t *list, unsigned int index);

// void list_for_each(list_t *list,
//                    void (*callback)(unsigned int index, const void *data, void *user_data),
//                    void *user_data);

// void list_for_each_reverse(list_t *list,
//                            void (*callback)(unsigned int index, const void *data, void *user_data),
//                            void *user_data);

// void list_reverse(list_t *list);

// int list_find(list_t *list, const void *search);
// int list_find_if(list_t *list,
//                  const void *search,
//                  int (*compare)(const void *data, const void *search, void *user_data),
//                  void *user_data);

#ifdef __cplusplus
}
#endif

#endif  /* __LIBSCL_LIST_H__ */