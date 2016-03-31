#ifndef SCL_LIST_H_
#define SCL_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Doubly linked list
 *
 *    @date   2016/03/31
 *    @author Jian <jianfan.tw@gmail.com>
 */

#include <stdbool.h>

typedef struct list_t list_t;

list_t * list_create(void);
void list_destroy(list_t *list);

bool list_empty(list_t *list);
unsigned int list_size(list_t *list);

void * list_at(list_t *list, unsigned int index);
void * list_front(list_t *list);
void * list_back(list_t *list);

int list_insert(list_t *list, unsigned int index, const void *data);
int list_erase(list_t *list, unsigned int index);

int list_push_front(list_t *list, const void *data);
int list_pop_front(list_t *list);
int list_push_back(list_t *list, const void *data);
int list_pop_back(list_t *list);

void list_for_each(list_t *list,
                   void (*callback)(unsigned int index, const void *data, void *user_data),
                   void *user_data);

void list_for_each_reverse(list_t *list,
                           void (*callback)(unsigned int index, const void *data, void *user_data),
                           void *user_data);

void list_reverse(list_t *list);

int list_find(list_t *list, const void *search);
int list_find_if(list_t *list,
                 const void *search,
                 int (*compare)(const void *data, const void *search, void *user_data),
                 void *user_data);

#ifdef __cplusplus
}
#endif

#endif  /* SCL_LIST_H_ */