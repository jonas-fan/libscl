#include <list_element.h>

#include <stdlib.h>
#include <string.h>

ListElement * list_element_create(void *data)
{
    ListElement *element = (ListElement *)malloc(sizeof(ListElement));

    if (element) {
        memset(element, 0, sizeof(*element));

        element->data = data;
        element->previous = NULL;
        element->next = NULL;
    }

    return element;
}

void list_element_destroy(ListElement *element)
{
    free(element);
}