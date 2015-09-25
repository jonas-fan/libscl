#ifndef SIMPLE_CONTAINER_LIST_H_
#define SIMPLE_CONTAINER_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Doubly linked list
 *
 *    @date   2015/09/25
 *    @author Jian <jianfan.tw@gmail.com>
 */

typedef struct list_t list_t;

list_t * list_create(void);
void list_destroy(list_t *list);

unsigned int list_size(const list_t *list);

void * list_at(const list_t *list, unsigned int index);
void * list_front(const list_t *list);
void * list_back(const list_t *list);

int list_insert(list_t *list, unsigned int index, const void *data);
int list_erase(list_t *list, unsigned int index);
int list_push_front(list_t *list, const void *data);
int list_pop_front(list_t *list);
int list_push_back(list_t *list, const void *data);
int list_pop_back(list_t *list);

void * list_find(const list_t *list, const void *data);
void * list_find_if(const list_t *list,
                    const void *data,
                    int (*compare)(const void *element, const void *data));

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_LIST_H_ */