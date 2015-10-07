#ifndef SIMPLE_CONTAINER_LIST_H_
#define SIMPLE_CONTAINER_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Doubly linked list
 *
 *    @date   2015/10/07
 *    @author Jian <jianfan.tw@gmail.com>
 */

typedef struct list_t list_t;

list_t * list_create(void);
void list_destroy(list_t *list);

unsigned int list_size(const list_t *list);

int list_at(const list_t *list, unsigned int index, void *data, unsigned int data_size);
int list_front(const list_t *list, void *data, unsigned int data_size);
int list_back(const list_t *list, void *data, unsigned int data_size);

int list_insert(list_t *list, unsigned int index, const void *data, unsigned int data_size);
int list_erase(list_t *list, unsigned int index);

int list_push_front(list_t *list, const void *data, unsigned int data_size);
int list_pop_front(list_t *list);
int list_push_back(list_t *list, const void *data, unsigned int data_size);
int list_pop_back(list_t *list);

int list_find(const list_t *list, const void *search, unsigned int search_size);
int list_find_if(const list_t *list,
                 const void *search,
                 unsigned int search_size,
                 int (*compare)(const void *data, unsigned int data_size, const void *search, unsigned int search_size));

void list_for_each(list_t *list,
                   void (*func)(unsigned int index, void *data, unsigned int data_size, void *user_data),
                   void *user_data);

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_LIST_H_ */