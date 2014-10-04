#include <vector.h>
#include <list.h>
#include <stdio.h>
#include <string.h>

bool equal(void *item, void *element)
{
    const char *lhs = (const char *)item;
    const char *rhs = (const char *)element;

    return !strcasecmp(lhs, rhs);
}

void vector_test()
{
    printf("--------------- Vector ----------------\n");

    Vector *vector = vector_create();

    vector_push_back(vector, "Hello");
    vector_push_back(vector, "World");
    vector_push_back(vector, "Very simple");
    vector_push_back(vector, "This is simple STL");
    vector_push_back(vector, "OTZ");

    printf("Vector = [");

    unsigned int index;

    for (index = 0; index < vector_size(vector); ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = vector_at(vector, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n\n");

    const char *dummy = "OTz";

    void *element = vector_find(vector, (void *)dummy);

    printf("vector_find: \"%s\" %s\n", dummy, (element)?  "Found" : "Not found");

    element = vector_find_if(vector, (void *)dummy, equal);

    printf("vector_find_if (strcasecmp): \"%s\" %s\n", dummy, (element)?  "Found" : "Not found");

    vector_destroy(vector);

    vector = NULL;

    printf("\n");
}

void list_test()
{
    printf("--------------- List ----------------\n");

    List *list = list_create();

    list_push_back(list, "aaa");
    list_push_back(list, "bbb");
    list_push_back(list, "ccc");
    list_push_back(list, "dddd");
    list_push_back(list, "eeee");
    list_push_back(list, "fff");

    unsigned int index;

    printf("List = [");

    for (index = 0; index < list_size(list); ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = list_at(list, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n");

    list_insert(list, 2, "123");

    printf("list_insert (index: %d) : %s\n", 2, "123");

    list_insert(list, 2, "test");

    printf("list_insert (index: %d) : %s\n", 2, "test");

    printf("List = [");

    for (index = 0; index < list_size(list); ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = list_at(list, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n");

    list_erase(list, 4);

    printf("list_erase (index: %d)\n", 4);

    printf("List = [");

    for (index = 0; index < list_size(list); ++index) {
        const char *delimiter = (!index)?  "" : ", ";

        void *element = list_at(list, index);

        printf("%s\"%s\"", delimiter, (char *)element);
    }

    printf("]\n\n");

    const char *dummy = "Test";

    void *element = list_find(list, (void *)dummy);

    printf("list_find: \"%s\" %s\n", dummy, (element)?  "Found" : "Not found");

    element = list_find_if(list, (void *)dummy, equal);

    printf("list_find_if (strcasecmp): \"%s\" %s\n", dummy, (element)?  "Found" : "Not found");

    list_destroy(list);

    list = NULL;

    printf("\n");
}

int main(const int argc, const char *argv[])
{
    vector_test();

    list_test();

    return 0;
}