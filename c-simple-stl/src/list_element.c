#include <list_element.h>
#include <stdlib.h>

ListElement * list_element_create(void *data)
{
    ListElement *list_element = (ListElement *)malloc(sizeof(ListElement));

    if (list_element) {
        list_element->data = data;
        list_element->previous = NULL;
        list_element->next = NULL;
    }

    return list_element;
}

void list_element_destroy(ListElement *list_element)
{
    free(list_element);
}