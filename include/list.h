#ifndef C_SIMPLE_STL_LIST_H_
#define C_SIMPLE_STL_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <list_element.h>

/**
 *    Simple List
 *
 *    @version 0.0.3
 *    @date    2014/06/18
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct list_t List;

List * list_create(void);
void list_destroy(List *list);

unsigned int list_size(const List *list);

void * list_at(const List *list, unsigned int index);
void * list_front(const List *list);
void * list_back(const List *list);

void list_insert(List *list, unsigned int index, void *data);
void list_erase(List *list, unsigned int index);
void list_push_front(List *list, void *data);
void list_pop_front(List *list);
void list_push_back(List *list, void *data);
void list_pop_back(List *list);

#ifdef __cplusplus
}
#endif

#endif  /* C_SIMPLE_STL_LIST_H_ */