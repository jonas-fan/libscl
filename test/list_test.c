#include "../src/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TEST(str) printf("# Test " str "\n")

int main(int argc, char *argv[])
{
    static int number[] = {0, 1, 2, 3};

    list_t *head = NULL;

    TEST("001");
    list_insert(&head, number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_delete(&head, head);
    assert(head == NULL);

    TEST("002");
    list_push_front(&head, number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("003");
    list_push_front(&head, number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("004");
    list_push_back(&head, number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("005");
    list_push_back(&head, number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("006");
    list_push_front(&head, number + 0);
    list_push_front(&head, number + 1);
    assert(head);
    assert(head != head->previous);
    assert(head != head->next);
    assert(head->previous == head->next);
    assert(head->data == number + 1);
    assert(head->next->data == number + 0);
    list_pop_front(&head);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("007");
    list_push_front(&head, number + 0);
    list_push_front(&head, number + 1);
    assert(head);
    assert(head != head->previous);
    assert(head != head->next);
    assert(head->previous == head->next);
    assert(head->data == number + 1);
    assert(head->next->data == number + 0);
    list_pop_back(&head);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 1);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("008");
    list_push_back(&head, number + 0);
    list_push_back(&head, number + 1);
    assert(head);
    assert(head != head->previous);
    assert(head != head->next);
    assert(head->previous == head->next);
    assert(head->data == number + 0);
    assert(head->next->data == number + 1);
    list_pop_front(&head);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 1);
    list_pop_front(&head);
    assert(head == NULL);

    TEST("009");
    list_push_back(&head, number + 0);
    list_push_back(&head, number + 1);
    assert(head);
    assert(head != head->previous);
    assert(head != head->next);
    assert(head->previous == head->next);
    assert(head->data == number + 0);
    assert(head->next->data == number + 1);
    list_pop_back(&head);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_pop_back(&head);
    assert(head == NULL);

    TEST("010");
    list_push_back(&head, number + 0);
    list_push_back(&head, number + 1);
    list_push_back(&head, number + 2);
    assert(head->data == number + 0);
    assert(head->next->data == number + 1);
    assert(head->next->next->data == number + 2);
    list_delete(&head, head->next);
    assert(head->data == number + 0);
    assert(head->next->data == number + 2);
    list_delete(&head, head);
    assert(head->data == number + 2);
    list_delete(&head, head);
    assert(head == NULL);

    printf("[\033[32mOK\033[m] looks good\n");

    return 0;
}