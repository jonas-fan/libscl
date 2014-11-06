#include <queue.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEST_SIZE 10
#define MAX_BUFFER_SIZE 64

bool equal(void *item, void *element)
{
    const char *lhs = (const char *)item;
    const char *rhs = (const char *)element;

    return !strcasecmp(lhs, rhs);
}

void dump(Queue *queue)
{
    printf("Queue => [");

    const unsigned int size = queue_size(queue);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = queue_at(queue, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n");
}

char * int2string(int number)
{
    char buffer[MAX_BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "%d", number);

    return strdup(buffer);
}

void test()
{
    Queue *queue = list_create();

    unsigned int index;

    for (index = 0; index < TEST_SIZE; ++index) {
        queue_push(queue, int2string(index));
    }

    assert(list_size(queue) == TEST_SIZE);

    dump(queue);

    const char *search = "3";

    void *element = queue_find(queue, (void *)search);

    assert(!element);

    element = queue_find_if(queue, (void *)search, equal);

    assert(element);

    element = queue_find_if(queue, (void *)search, NULL);

    assert(!element);

    char *first_element = (char *)queue_front(queue);

    assert(atoi(first_element) == 0);

    free(first_element);

    queue_pop(queue);

    assert(queue_size(queue) == (TEST_SIZE - 1));

    while (queue_size(queue)) {
        char *element = (char *)queue_front(queue);

        free(element);

        queue_pop(queue);
    }

    assert(queue_size(queue) == 0);

    queue_destroy(queue);

    printf("[\033[32mOK\033[m]\n");
}

int main(const int argc, const char *argv[])
{
    test();

    return 0;
}