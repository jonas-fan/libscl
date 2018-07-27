#include "../src/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TEST(str) printf("# Test " str "\n")

int main(int argc, char *argv[])
{
    static int number[] = {0, 1, 2, 3};

    list_t *head;

    TEST("001");
    head = list_new(number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_delete(&head);
    assert(head == NULL);

    TEST("002");
    head = list_new(NULL);
    assert(head);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("003");
    head = list_new(NULL);
    assert(head);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("004");
    head = list_new(NULL);
    assert(head);
    assert(list_push_front(&head, NULL));
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head != head->previous);
    assert(head != head->next);
    list_pop_front(&head);
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head == head->previous);
    assert(head == head->next);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("005");
    head = list_new(NULL);
    assert(head);
    assert(list_push_front(&head, NULL));
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head != head->previous);
    assert(head != head->next);
    list_pop_back(&head);
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head == head->previous);
    assert(head == head->next);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("006");
    head = list_new(NULL);
    assert(head);
    assert(list_push_back(&head, NULL));
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head != head->previous);
    assert(head != head->next);
    list_pop_front(&head);
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head == head->previous);
    assert(head == head->next);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("007");
    head = list_new(NULL);
    assert(head);
    assert(list_push_back(&head, NULL));
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head != head->previous);
    assert(head != head->next);
    list_pop_back(&head);
    assert(head);
    assert(head->previous);
    assert(head->next);
    assert(head->previous == head->next);
    assert(head == head->previous);
    assert(head == head->next);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("008");
    head = list_new(number + 0);
    assert(head->data == number + 0);
    assert(list_push_front(&head, number + 1));
    assert(head->data == number + 1);
    assert(head->previous->data == number + 0);
    assert(head->next->data == number + 0);
    list_pop_front(&head);
    assert(head->data == number + 0);
    list_delete(&head);
    assert(head == NULL);

    TEST("009");
    head = list_new(number + 0);
    assert(head->data == number + 0);
    assert(list_push_front(&head, number + 1));
    assert(head->data == number + 1);
    assert(head->previous->data == number + 0);
    assert(head->next->data == number + 0);
    list_pop_back(&head);
    assert(head->data == number + 1);
    list_delete(&head);
    assert(head == NULL);

    TEST("010");
    head = list_new(number + 0);
    assert(head->data == number + 0);
    assert(list_push_back(&head, number + 1));
    assert(head->data == number + 0);
    assert(head->previous->data == number + 1);
    assert(head->next->data == number + 1);
    list_pop_front(&head);
    assert(head->data == number + 1);
    list_delete(&head);
    assert(head == NULL);

    TEST("011");
    head = list_new(number + 0);
    assert(head->data == number + 0);
    assert(list_push_back(&head, number + 1));
    assert(head->data == number + 0);
    assert(head->previous->data == number + 1);
    assert(head->next->data == number + 1);
    list_pop_back(&head);
    assert(head->data == number + 0);
    list_delete(&head);
    assert(head == NULL);

    printf("[\033[32mOK\033[m] looks good\n");

    return 0;
}