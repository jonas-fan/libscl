#include "../src/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static unsigned int count = 0;

#define TEST(str) printf("# Test %03u " str "\n", ++count)

int main(int argc, char *argv[])
{
    static int number[] = {
        1 << 0,
        1 << 1,
        1 << 2,
        1 << 3,
        1 << 4,
        1 << 5,
        1 << 6,
        1 << 7,
    };

    list_t *head = NULL;

    TEST("list_insert + list_delete");
    list_insert(&head, number + 0);
    assert(head);
    assert(head == head->previous);
    assert(head == head->next);
    assert(head->data == number + 0);
    list_delete(&head, head);
    assert(head == NULL);

    // TEST("list_push_front + list_pop_front");
    // list_push_front(&head, number + 0);
    // assert(head);
    // assert(head == head->previous);
    // assert(head == head->next);
    // assert(head->data == number + 0);
    // list_pop_front(&head);
    // assert(head == NULL);

    // TEST("list_push_front + list_pop_back");
    // list_push_front(&head, number + 0);
    // assert(head);
    // assert(head == head->previous);
    // assert(head == head->next);
    // assert(head->data == number + 0);
    // list_pop_back(&head);
    // assert(head == NULL);

    // TEST("list_push_back + list_pop_front");
    // list_push_back(&head, number + 0);
    // assert(head);
    // assert(head == head->previous);
    // assert(head == head->next);
    // assert(head->data == number + 0);
    // list_pop_front(&head);
    // assert(head == NULL);

    // TEST("list_push_back + list_pop_back");
    // list_push_back(&head, number + 0);
    // assert(head);
    // assert(head == head->previous);
    // assert(head == head->next);
    // assert(head->data == number + 0);
    // list_pop_back(&head);
    // assert(head == NULL);

    TEST("list_push_front + list_pop_front");
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

    TEST("list_push_front + list_pop_back");
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

    TEST("list_push_back + list_pop_front");
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

    TEST("list_push_back + list_pop_back");
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

    TEST("list_push_back + list_delete");
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

    TEST("list_for_each");
    list_push_back(&head, number + 0);
    list_push_back(&head, number + 1);
    list_push_back(&head, number + 2);
    list_push_back(&head, number + 3);
    list_push_back(&head, number + 4);

    unsigned int index = 0;
    list_t *entry;

    list_for_each(head, entry) {
        assert(entry->data == number + index);
        ++index;
    }

    printf("[\033[32mOK\033[m] looks good\n");

    return 0;
}