#include <list.h>
#include <stdlib.h>

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
    if (index >= list->size) {
        return NULL;
    }

    ListElement *element = list->head;

    while (index--) {
        element = element->next;
    }

    return element->data;
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

void list_insert(List *list, unsigned int index, void *element)
{
    if (index >= list->size) {
        return;
    }

    ListElement *new_element = (ListElement *)malloc(sizeof(ListElement));

    new_element->data = element;
    new_element->previous = NULL;
    new_element->next = NULL;

    ListElement *current_element = list->head;

    while (index--) {
        current_element = current_element->next;
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
    if (index >= list->size) {
        return;
    }

    ListElement *current_element = list->head;

    while (index--) {
        current_element = current_element->next;
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

    free(current_element);
}

void list_push_front(List *list, void *element)
{
    ListElement *new_element = (ListElement *)malloc(sizeof(ListElement));

    new_element->data = element;
    new_element->previous = NULL;
    new_element->next = NULL;

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

    free(element);
}

void list_push_back(List *list, void *element)
{
    ListElement *new_element = (ListElement *)malloc(sizeof(ListElement));

    new_element->data = element;
    new_element->previous = NULL;
    new_element->next = NULL;

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

    free(element);
}