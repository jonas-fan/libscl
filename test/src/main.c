#include <vector.h>
#include <stdio.h>
#include <string.h>

int compare(const void *x, const void *y)
{
    const char **lhs = (const char **)x;
    const char **rhs = (const char **)y;

    return strcmp(*lhs, *rhs);
}

int main(const int argc, const char *argv[])
{
    Vector *vector = vector_create();

    vector_push_back(vector, "Hello");
    vector_push_back(vector, "World");
    vector_push_back(vector, "Very simple");
    vector_push_back(vector, "This is simple STL");
    vector_push_back(vector, "OTZ");

    printf("--------------- Before ----------------\n");

    void **iterator;

    for (iterator = vector_begin(vector); iterator != vector_end(vector); ++iterator) {
        printf("%s\n", (char *)(*iterator));
    }

    printf("--------------- After -----------------\n");

    vector_sort(vector, compare);

    unsigned int index;

    for (index = 0; index < vector_size(vector); ++index) {
        void *element = vector_at(vector, index);

        printf("%s\n", (char *)element);
    }

    vector_destroy(vector);

    vector = NULL;

    return 0;
}