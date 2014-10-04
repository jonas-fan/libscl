#include <list.h>
#include <list_element.h>

#include <stdlib.h>
#include <string.h>


/**
 *    Private
 */

struct list_t
{
    unsigned int size;
    ListElement *head;
    ListElement *tail;
};

static ListElement * list_at_(const List *list, unsigned int index);


/**
 *    Public methods
 */

List * list_create(void)
{
    List *list = (List *)malloc(sizeof(List));

    if (list) {
        memset(list, 0, sizeof(*list));

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
    ListElement *element = list_at_(list, index);

    if (element) {
        return element->data;
    }

    return NULL;
}

void * list_front(const List *list)
{
    return list_at(list, 0);
}

void * list_back(const List *list)
{
    return list_at(list, list->size - 1);
}

void list_insert(List *list, unsigned int index, void *data)
{
    ListElement *current_element = list_at_(list, index);

    if (!current_element) {
        return;
    }

    ListElement *new_element = list_element_create(data);

    if (!new_element) {
        return;
    }

    new_element->next = current_element;
    new_element->previous = current_element->previous;

    if (list->head == current_element) {
        list->head = new_element;
    }
    else {
        current_element->previous->next = new_element;
    }

    current_element->previous = new_element;

    ++list->size;
}

void list_erase(List *list, unsigned int index)
{
    ListElement *current_element = list_at_(list, index);

    if (!current_element) {
        return;
    }

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else if (current_element == list->head) {
        current_element->next->previous = NULL;
        list->head = current_element->next;
    }
    else if (current_element == list->tail) {
        current_element->previous->next = NULL;
        list->tail = current_element->previous;
    }
    else {
        current_element->next->previous = current_element->previous;
        current_element->previous->next = current_element->next;
    }

    --list->size;

    list_element_destroy(current_element);
}

void list_push_front(List *list, void *data)
{
    ListElement *new_element = list_element_create(data);

    if (!new_element) {
        return;
    }

    if (list->head) {
        new_element->next = list->head;
        list->head->previous = new_element;
        list->head = new_element;
    }
    else {
        list->head = new_element;
        list->tail = new_element;
    }

    ++list->size;
}

void list_pop_front(List *list)
{
    if (!list->size) {
        return;
    }

    ListElement *element = list->head;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = element->next;
        list->head->previous = NULL;
    }

    --list->size;

    list_element_destroy(element);
}

void list_push_back(List *list, void *data)
{
    ListElement *new_element = list_element_create(data);

    if (!new_element) {
        return;
    }

    if (list->tail) {
        new_element->previous = list->tail;
        list->tail->next = new_element;
        list->tail = new_element;
    }
    else {
        list->head = new_element;
        list->tail = new_element;
    }

    ++list->size;
}

void list_pop_back(List *list)
{
    if (!list->size) {
        return;
    }

    ListElement *element = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = element->previous;
        list->tail->next = NULL;
    }

    --list->size;

    list_element_destroy(element);
}

void * list_find(const List *list, void *item)
{
    unsigned int index;

    for (index = 0; index < list->size; ++index) {
        void *element = list_at(list, index);

        if (item == element) {
            return element;
        }
    }

    return NULL;
}

void * list_find_if(const List *list, void *item, bool (*predicate)(void *item, void *element))
{
    unsigned int index;

    for (index = 0; index < list->size; ++index) {
        void *element = list_at(list, index);

        if (predicate(item, element)) {
            return element;
        }
    }

    return NULL;
}


/**
 *    Private methods
 */

static ListElement * list_at_(const List *list, unsigned int index)
{
    if (index >= list->size) {
        return NULL;
    }

    ListElement *element = list->head;

    while (index--) {
        element = element->next;
    }

    return element;
}