#include <list.h>

List * list_create(void)
{
    List *list = (List *)malloc(sizeof(List));

    if (list) {
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
    }

    return list;
}

void list_destroy(List *list)
{
    while (list->size) {
        list_pop_back(list);
    }

    free(list);
}

unsigned int list_size(const List *list)
{
    return list->size;
}

void * list_at(const List *list, unsigned int index)
{
    if (index < list->size) {
        ListElement *element = list->head;

        while (index--) {
            element = element->next;
        }

        return element->data;
    }

    return NULL;
}

void * list_front(const List *list)
{
    ListElement *head = list->head;

    if (head) {
        return head->data;
    }

    return NULL;
}

void * list_back(const List *list)
{
    ListElement *tail = list->tail;

    if (tail) {
        return tail->data;
    }

    return NULL;
}

void list_push_back(List *list, void *element)
{
    ListElement *e = (ListElement *)malloc(sizeof(ListElement));

    e->data = element;
    e->previous = NULL;
    e->next = NULL;

    if (list->tail) {
        e->previous = list->tail;
        list->tail->next = e;
        list->tail = e;
    }
    else {
        list->head = e;
        list->tail = e;
    }

    ++list->size;
}

void list_pop_back(List *list)
{
    if (!list->size) {
        return;
    }

    ListElement *tail = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = tail->previous;
        list->tail->next = NULL;
    }

    --list->size;

    free(tail);
}