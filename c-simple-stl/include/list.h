#ifndef SIMPLE_LIST_H_
#define SIMPLE_LIST_H_

#include <stdlib.h>

/**
 *    Simple List
 *
 *    @version 0.0.1
 *    @date    2014/06/17
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct list_element_t
{
    void *data;
    struct list_element_t *previous;
    struct list_element_t *next;
} ListElement;

typedef struct list_t
{
    unsigned int size;
    ListElement *head;
    ListElement *tail;
} List;

List * list_create(void);
void list_destroy(List *list);

unsigned int list_size(const List *list);

void * list_at(const List *list, unsigned int index);
void * list_front(const List *list);
void * list_back(const List *list);

void list_push_back(List *list, void *element);
void list_pop_back(List *list);

#endif  // SIMPLE_LIST_H_