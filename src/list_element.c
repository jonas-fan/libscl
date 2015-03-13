#include <list_element.h>

#include <stdlib.h>
#include <string.h>


/**
 *    Public methods
 */

ListElement * list_element_create(const void *data)
{
    ListElement *element = (ListElement *)malloc(sizeof(ListElement));

    if (element) {
        memset(element, 0, sizeof(*element));

        element->data = (void *)data;
        element->previous = NULL;
        element->next = NULL;
    }

    return element;
}

void list_element_destroy(ListElement *element)
{
    free(element);
}