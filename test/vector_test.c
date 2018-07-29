#include "../src/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define TEST(str) printf("# Test %03u " str "\n", ++count)

static unsigned int count = 0;

int main(int argc, char *argv[])
{
    struct vector vector;
    struct vector_entry *entry1;
    struct vector_entry *entry2;
    struct vector_entry *entry3;
    struct vector_entry *next;
    void *data;
    const int number1 = 1;
    const int number2 = 2;
    const int number3 = 3;
    const int *numbers[] = {&number1, &number2, &number3};
    int rc = 0;
    unsigned int size = 0;
    unsigned int index = 0;

    TEST("vector_init");
    vector_init(&vector);
    assert(vector.entries == NULL);
    assert(vector.size == 0);
    assert(vector.capacity == 0);

    TEST("vector_size");
    size = vector_size(&vector);
    assert(size == 0);

    TEST("vector_empty");
    rc = vector_empty(&vector);
    assert(rc == 1);

    TEST("vector_insert");
    entry1 = vector_insert(&vector, 0, &number1);
    assert(entry1);
    assert(entry1->data == &number1);
    assert(vector.capacity == 1);
    size = vector_size(&vector);
    assert(size == 1);
    rc = vector_empty(&vector);
    assert(rc == 0);

    TEST("vector_erase");
    entry1 = vector_erase(&vector, 0);
    assert(entry1 == NULL);
    size = vector_size(&vector);
    assert(size == 0);
    rc = vector_empty(&vector);
    assert(rc == 1);

    TEST("vector_term");
    vector_term(&vector);
    assert(vector.entries == NULL);
    assert(vector.size == 0);
    assert(vector.capacity == 0);

    vector_init(&vector);

    TEST("vector_push_back");
    vector_push_back(&vector, &number1);
    assert(vector.size == 1);
    assert(vector.capacity == 1);
    size = vector_size(&vector);
    assert(size == 1);
    vector_push_back(&vector, &number3);
    assert(vector.size == 2);
    assert(vector.capacity == 2);
    size = vector_size(&vector);
    assert(size == 2);
    entry2 = vector_insert(&vector, 1, &number2);
    assert(entry2);
    assert(entry2->data == &number2);
    assert(vector.size == 3);
    assert(vector.capacity == 4);
    size = vector_size(&vector);
    assert(size == 3);

    TEST("vector_at");
    data = vector_at(&vector, 1);
    assert(data == &number2);

    TEST("vector_front");
    entry1 = vector_front(&vector);
    assert(entry1);
    assert(entry1->data == &number1);

    TEST("vector_back");
    entry3 = vector_back(&vector);
    assert(entry3);
    assert(entry3->data == &number3);
    assert(entry2 - 1 == entry1);
    assert(entry2 + 1 == entry3);

    TEST("vector_pop_back");
    next = vector_erase(&vector, 1);
    entry3 = vector_back(&vector);
    assert(next == entry3);
    size = vector_size(&vector);
    assert(size == 2);
    vector_pop_back(&vector);
    entry1 = vector_back(&vector);
    assert(entry1->data == &number1);
    assert(vector.size == 1);
    assert(vector.capacity == 4);
    size = vector_size(&vector);
    assert(size == 1);
    vector_pop_back(&vector);
    assert(vector.size == 0);
    assert(vector.capacity == 4);
    size = vector_size(&vector);
    assert(size == 0);
    rc = vector_empty(&vector);
    assert(rc == 1);

    TEST("vector_for_each");
    vector_push_back(&vector, numbers[0]);
    vector_push_back(&vector, numbers[1]);
    vector_push_back(&vector, numbers[2]);

    index = 0;

    vector_for_each(&vector, entry1) {
        assert(entry1->data == numbers[index++]);
    }

    vector_pop_back(&vector);
    vector_pop_back(&vector);
    vector_pop_back(&vector);

    TEST("vector_for_each_reverse");
    vector_push_back(&vector, numbers[0]);
    vector_push_back(&vector, numbers[1]);
    vector_push_back(&vector, numbers[2]);

    index = ARRAY_SIZE(numbers) - 1;

    vector_for_each_reverse(&vector, entry1) {
        assert(entry1->data == numbers[index--]);
    }

    vector_pop_back(&vector);
    vector_pop_back(&vector);
    vector_pop_back(&vector);

    vector_term(&vector);

    printf("[OK]\n");

    return 0;
}