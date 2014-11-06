#include <vector.h>

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

void dump(Vector *vector)
{
    printf("Vector => [");

    const unsigned int size = vector_size(vector);

    unsigned int index;

    for (index = 0; index < size; ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = vector_at(vector, index);

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
    Vector *vector = vector_create();

    unsigned int index;

    for (index = 0; index < TEST_SIZE; ++index) {
        vector_push_back(vector, int2string(index));
    }

    assert(vector_size(vector) == TEST_SIZE);

    dump(vector);

    const char *search = "3";

    void *element = vector_find(vector, (void *)search);

    assert(!element);

    element = vector_find_if(vector, (void *)search, equal);

    assert(element);

    element = vector_find_if(vector, (void *)search, NULL);

    assert(!element);

    char *last_element = (char *)vector_back(vector);

    assert(atoi(last_element) == (TEST_SIZE - 1));

    free(last_element);

    vector_pop_back(vector);

    assert(vector_size(vector) == (TEST_SIZE - 1));

    while (vector_size(vector)) {
        char *element = (char *)vector_back(vector);

        free(element);

        vector_pop_back(vector);
    }

    assert(vector_size(vector) == 0);

    vector_destroy(vector);

    printf("[\033[32mOK\033[m]\n");
}

int main(const int argc, const char *argv[])
{
    test();

    return 0;
}