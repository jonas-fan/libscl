#ifndef SIMPLE_CONTAINER_LIST_ELEMENT_H_
#define SIMPLE_CONTAINER_LIST_ELEMENT_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Simple ListElement
 *
 *    @version 0.1.1
 *    @date    2015/03/13
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct list_element_t ListElement;

struct list_element_t
{
    void *data;
    ListElement *previous;
    ListElement *next;
};

ListElement * list_element_create(const void *data);
void list_element_destroy(ListElement *list_element);

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_LIST_ELEMENT_H_ */