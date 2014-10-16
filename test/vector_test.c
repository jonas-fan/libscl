#include <vector.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>

bool equal(void *item, void *element)
{
    const char *lhs = (const char *)item;
    const char *rhs = (const char *)element;

    return !strcasecmp(lhs, rhs);
}

void vector_test()
{
    Vector *vector = vector_create();

    vector_push_back(vector, "Hello");
    vector_push_back(vector, "World");
    vector_push_back(vector, "Very simple");
    vector_push_back(vector, "This is simple STL");
    vector_push_back(vector, "OTZ");

    assert(vector_size(vector) == 5);

    printf("Vector = [");

    unsigned int index;

    for (index = 0; index < vector_size(vector); ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = vector_at(vector, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n");

    const char *dummy = "OTz";

    void *element = vector_find(vector, (void *)dummy);

    assert(!element);

    printf("vector_find: \"%s\" %s\n", dummy, (element)?  "Found" : "Not found");

    element = vector_find_if(vector, (void *)dummy, equal);

    assert(element);

    printf("vector_find_if (strcasecmp): \"%s\" %s\n", dummy, (element)?  "Found" : "Not found");

    vector_pop_back(vector);

    assert(vector_size(vector) == 4);

    assert(!strcmp(vector_at(vector, 2), "Very simple"));

    vector_destroy(vector);

    vector = NULL;

    printf("OK\n");
}

int main(const int argc, const char *argv[])
{
    vector_test();

    return 0;
}