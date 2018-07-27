#include "../lib/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TEST(str) printf("# Test %03u " str "\n", ++count)

static unsigned int count = 0;

int main(int argc, char *argv[])
{
    struct list list;
    struct list_entry *entry1;
    struct list_entry *entry2;
    struct list_entry *entry3;
    struct list_entry *next;
    const int number1 = 1;
    const int number2 = 2;
    const int number3 = 3;
    const int *numbers[] = {&number1, &number2, &number3};
    const int **number;
    int rc;

    TEST("list_init");
    list_init(&list);
    assert(list.head == NULL);

    TEST("list_term");
    list_term(&list);
    assert(list.head == NULL);

    list_init(&list);

    TEST("list_empty");
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_insert");
    entry1 = list_insert(&list, list.head, &number1);
    assert(entry1);
    assert(entry1 == list.head);
    assert(entry1->previous == entry1);
    assert(entry1->next == entry1);
    assert(entry1->data == &number1);
    entry2 = list_insert(&list, list.head, &number2);
    assert(entry2);
    assert(entry2 == list.head);
    assert(entry2->previous == entry1);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry2);
    assert(entry1->data == &number1);

    TEST("list_front");
    entry2 = list_front(&list);
    assert(entry2);
    assert(entry2 == list.head);
    assert(entry2->previous == entry1);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);

    TEST("list_back");
    entry1 = list_back(&list);
    assert(entry1);
    assert(entry1 != list.head);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry2);
    assert(entry1->data == &number1);

    TEST("list_erase");
    next = list_erase(&list, entry2);
    assert(next == entry1);
    assert(next == list.head);
    assert(next->previous == entry1);
    assert(next->next == entry1);
    assert(next->data == &number1);
    rc = list_empty(&list);
    assert(rc == 0);
    next = list_erase(&list, next);
    assert(next == NULL);
    assert(list.head == NULL);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_insert * n");
    entry1 = list_insert(&list, list.head, &number1);
    entry2 = list_insert(&list, list.head, &number2);
    entry3 = list_insert(&list, list.head, &number3);
    assert(entry3);
    assert(entry3 == list.head);
    assert(entry3->previous == entry1);
    assert(entry3->next == entry2);
    assert(entry3->data == &number3);
    assert(entry2->previous == entry3);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry3);
    assert(entry1->data == &number1);
    next = list_erase(&list, entry2);
    assert(next);
    assert(next == entry1);
    assert(entry3 == list.head);
    assert(entry3->previous == entry1);
    assert(entry3->next == entry1);
    assert(entry3->data == &number3);
    assert(entry1->previous == entry3);
    assert(entry1->next == entry3);
    assert(entry1->data == &number1);
    next = list_erase(&list, next);
    assert(next);
    assert(next == entry3);
    assert(entry3 == list.head);
    assert(entry3->previous == entry3);
    assert(entry3->next == entry3);
    assert(entry3->data == &number3);
    next = list_erase(&list, next);
    assert(next == NULL);

    TEST("list_push_front + list_pop_front");
    list_push_front(&list, &number1);
    list_push_front(&list, &number2);
    entry2 = list_front(&list);
    entry1 = list_back(&list);
    assert(entry2);
    assert(entry2 == list.head);
    assert(entry2->previous == entry1);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry2);
    assert(entry1->data == &number1);
    list_pop_front(&list);
    assert(entry1);
    assert(entry1 == list.head);
    assert(entry1->previous == entry1);
    assert(entry1->next == entry1);
    assert(entry1->data == &number1);
    list_pop_front(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_front + list_pop_back");
    list_push_front(&list, &number1);
    list_push_front(&list, &number2);
    entry2 = list_front(&list);
    entry1 = list_back(&list);
    assert(entry2);
    assert(entry2 == list.head);
    assert(entry2->previous == entry1);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry2);
    assert(entry1->data == &number1);
    list_pop_back(&list);
    assert(entry2);
    assert(entry2 == list.head);
    assert(entry2->previous == entry2);
    assert(entry2->next == entry2);
    assert(entry2->data == &number2);
    list_pop_back(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_back + list_pop_front");
    list_push_back(&list, &number1);
    list_push_back(&list, &number2);
    entry1 = list_front(&list);
    entry2 = list_back(&list);
    assert(entry1);
    assert(entry1 == list.head);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry2);
    assert(entry1->data == &number1);
    assert(entry2->previous == entry1);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);
    list_pop_front(&list);
    assert(entry2);
    assert(entry2 == list.head);
    assert(entry2->previous == entry2);
    assert(entry2->next == entry2);
    assert(entry2->data == &number2);
    list_pop_front(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_back + list_pop_back");
    list_push_back(&list, &number1);
    list_push_back(&list, &number2);
    entry1 = list_front(&list);
    entry2 = list_back(&list);
    assert(entry1);
    assert(entry1 == list.head);
    assert(entry1->previous == entry2);
    assert(entry1->next == entry2);
    assert(entry1->data == &number1);
    assert(entry2->previous == entry1);
    assert(entry2->next == entry1);
    assert(entry2->data == &number2);
    list_pop_back(&list);
    assert(entry1);
    assert(entry1 == list.head);
    assert(entry1->previous == entry1);
    assert(entry1->next == entry1);
    assert(entry1->data == &number1);
    list_pop_back(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_for_each");
    list_push_back(&list, numbers[0]);
    list_push_back(&list, numbers[1]);
    list_push_back(&list, numbers[2]);

    number = numbers;

    list_for_each(&list, entry1) {
        assert(entry1->data == *number);
        ++number;
    }

    list_pop_back(&list);
    list_pop_back(&list);
    list_pop_back(&list);

    TEST("list_for_each_reverse");
    list_push_back(&list, numbers[0]);
    list_push_back(&list, numbers[1]);
    list_push_back(&list, numbers[2]);

    number = numbers + 2;

    list_for_each_reverse(&list, entry1) {
        assert(entry1->data == *number);
        --number;
    }

    list_pop_back(&list);
    list_pop_back(&list);
    list_pop_back(&list);

    list_term(&list);

    printf("[OK]\n");

    return 0;
}