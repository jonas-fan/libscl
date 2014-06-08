#include <stdio.h>
#include <vector.h>

int main(const int argc, const char *argv[])
{
    Vector *vector = vector_create();

    vector_push_back(vector, "Hello");
    vector_push_back(vector, "World");
    vector_push_back(vector, "This is simple STL");
    vector_push_back(vector, "Very simple");

    void **iterator;

    for (iterator = vector_begin(vector); iterator != vector_end(vector); ++iterator) {
        printf("%s\n", (char *)(*iterator));
    }

    vector_pop_back(vector);
    vector_pop_back(vector);

    for (iterator = vector_begin(vector); iterator != vector_end(vector); ++iterator) {
        printf("%s\n", (char *)(*iterator));
    }

    vector_destroy(vector);

    vector = NULL;

    return 0;
}