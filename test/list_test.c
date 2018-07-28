#include "../src/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define TEST(str) printf("# Test %03u " str "\n", ++count)

static unsigned int count = 0;

int main(int argc, char *argv[])
{
    struct list list;
    struct list_entry entry1;
    struct list_entry entry2;
    struct list_entry entry3;
    struct list_entry *entry;
    int number1 = 1;
    int number2 = 2;
    int number3 = 3;
    int *numbers[] = {&number1, &number2, &number3};
    int rc = 0;
    unsigned int index = 0;

    TEST("list_entry_init");
    list_entry_init(&entry1, &number1);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);
    list_entry_init(&entry2, &number2);
    assert(entry2.previous == &entry2);
    assert(entry2.next == &entry2);
    assert(entry2.data == &number2);
    list_entry_init(&entry3, &number3);
    assert(entry3.previous == &entry3);
    assert(entry3.next == &entry3);
    assert(entry3.data == &number3);

    TEST("list_init");
    list_init(&list);
    assert(list.head == NULL);

    TEST("list_empty");
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_insert");
    list_entry_init(&entry1, &number1);
    list_insert(&list, list.head, &entry1);
    assert(list.head == &entry1);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);

    TEST("list_erase");
    list_erase(&list, &entry1);
    assert(list.head == NULL);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);

    TEST("list_insert * n");
    list_insert(&list, list.head, &entry1);
    list_insert(&list, list.head, &entry2);
    list_insert(&list, list.head, &entry3);
    assert(list.head == &entry3);
    assert(entry3.previous == &entry1);
    assert(entry3.next == &entry2);
    assert(entry3.data == &number3);
    assert(entry2.previous == &entry3);
    assert(entry2.next == &entry1);
    assert(entry2.data == &number2);
    assert(entry1.previous == &entry2);
    assert(entry1.next == &entry3);
    assert(entry1.data == &number1);
    list_erase(&list, &entry2);
    assert(entry2.previous == &entry2);
    assert(entry2.next == &entry2);
    assert(entry2.data == &number2);
    assert(list.head == &entry3);
    assert(entry3.previous == &entry1);
    assert(entry3.next == &entry1);
    assert(entry3.data == &number3);
    assert(entry1.previous == &entry3);
    assert(entry1.next == &entry3);
    assert(entry1.data == &number1);
    list_erase(&list, &entry1);
    list_erase(&list, &entry3);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_front + list_pop_front");
    list_push_front(&list, &entry1);
    list_push_front(&list, &entry2);
    assert(list.head == &entry2);
    assert(entry2.previous == &entry1);
    assert(entry2.next == &entry1);
    assert(entry2.data == &number2);
    assert(entry1.previous == &entry2);
    assert(entry1.next == &entry2);
    assert(entry1.data == &number1);
    list_pop_front(&list);
    assert(list.head == &entry1);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);
    assert(entry2.previous == &entry2);
    assert(entry2.next == &entry2);
    assert(entry2.data == &number2);
    list_pop_front(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_front + list_pop_back");
    list_push_front(&list, &entry1);
    list_push_front(&list, &entry2);
    assert(list.head == &entry2);
    assert(entry2.previous == &entry1);
    assert(entry2.next == &entry1);
    assert(entry2.data == &number2);
    assert(entry1.previous == &entry2);
    assert(entry1.next == &entry2);
    assert(entry1.data == &number1);
    list_pop_back(&list);
    assert(list.head == &entry2);
    assert(entry2.previous == &entry2);
    assert(entry2.next == &entry2);
    assert(entry2.data == &number2);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);
    list_pop_back(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_back + list_pop_front");
    list_push_back(&list, &entry1);
    list_push_back(&list, &entry2);
    assert(list.head == &entry1);
    assert(entry1.previous == &entry2);
    assert(entry1.next == &entry2);
    assert(entry1.data == &number1);
    assert(entry2.previous == &entry1);
    assert(entry2.next == &entry1);
    assert(entry2.data == &number2);
    list_pop_front(&list);
    assert(list.head == &entry2);
    assert(entry2.previous == &entry2);
    assert(entry2.next == &entry2);
    assert(entry2.data == &number2);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);
    list_pop_front(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_push_back + list_pop_back");
    list_push_back(&list, &entry1);
    list_push_back(&list, &entry2);
    assert(list.head == &entry1);
    assert(entry1.previous == &entry2);
    assert(entry1.next == &entry2);
    assert(entry1.data == &number1);
    assert(entry2.previous == &entry1);
    assert(entry2.next == &entry1);
    assert(entry2.data == &number2);
    list_pop_back(&list);
    assert(list.head == &entry1);
    assert(entry1.previous == &entry1);
    assert(entry1.next == &entry1);
    assert(entry1.data == &number1);
    assert(entry2.previous == &entry2);
    assert(entry2.next == &entry2);
    assert(entry2.data == &number2);
    list_pop_back(&list);
    rc = list_empty(&list);
    assert(rc == 1);

    TEST("list_for_each");
    list_push_back(&list, &entry1);
    list_push_back(&list, &entry2);
    list_push_back(&list, &entry3);

    index = 0;

    list_for_each(&list, entry) {
        assert(entry->data == numbers[index++]);
    }

    list_pop_back(&list);
    list_pop_back(&list);
    list_pop_back(&list);

    TEST("list_for_each_reverse");
    list_push_back(&list, &entry1);
    list_push_back(&list, &entry2);
    list_push_back(&list, &entry3);

    index = ARRAY_SIZE(numbers) - 1;

    list_for_each_reverse(&list, entry) {
        assert(entry->data == numbers[index--]);
    }

    list_pop_back(&list);
    list_pop_back(&list);
    list_pop_back(&list);

    printf("[OK]\n");

    return 0;
}