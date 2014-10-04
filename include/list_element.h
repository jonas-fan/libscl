#ifndef C_SIMPLE_STL_LIST_ELEMENT_H_
#define C_SIMPLE_STL_LIST_ELEMENT_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Simple ListElement
 *
 *    @version 0.1.0
 *    @date    2014/10/04
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct list_element_t
{
    void *data;
    struct list_element_t *previous;
    struct list_element_t *next;
} ListElement;

ListElement * list_element_create(void *data);
void list_element_destroy(ListElement *list_element);

#ifdef __cplusplus
}
#endif

#endif  /* C_SIMPLE_STL_LIST_ELEMENT_H_ */