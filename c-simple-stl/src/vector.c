#include <vector.h>
#include <string.h>

Vector * vector_create()
{
    Vector *vector = (Vector *)malloc(sizeof(Vector));

    if (vector) {
        vector->data = NULL;
        vector->size = 0;
        vector->capacity = 0;
    }

    return vector;
}

void vector_destroy(Vector *vector)
{
    free(vector->data);
    free(vector);
}

unsigned int vector_size(const Vector *vector)
{
    return vector->size;
}

unsigned int vector_capacity(const Vector *vector)
{
    return vector->capacity;
}

void * vector_at(const Vector *vector, unsigned int index)
{
    if (index < vector->size) {
        return vector->data[index];
    }

    return NULL;
}

void * vector_front(const Vector *vector)
{
    return vector_at(vector, 0);
}

void * vector_back(const Vector *vector)
{
    return vector_at(vector, vector->size - 1);
}

void ** vector_begin(Vector *vector)
{
    return vector->data;
}

void ** vector_end(Vector *vector)
{
    return vector->data + vector->size;
}

void vector_push_back(Vector *vector, void *element)
{
    if (vector->size >= vector->capacity) {
        vector->capacity = (vector->capacity)?  vector->capacity << 1 : 1;

        size_t data_size = sizeof(void *) * vector->capacity;

        if (vector->data) {
            vector->data = realloc(vector->data, data_size);
        }
        else {
            vector->data = malloc(data_size);
        }
    }

    vector->data[vector->size++] = element;
}

void vector_pop_back(Vector *vector)
{
    if (vector->size) {
        vector->data[vector->size--] = NULL;
    }
}
