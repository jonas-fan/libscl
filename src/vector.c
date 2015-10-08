#include <vector.h>

#include <stdlib.h>
#include <string.h>

struct vector_t
{
    void **data;
    unsigned int size;
    unsigned int capacity;
};

static inline void * vector_at_(const vector_t *vector, unsigned int index)
{
    if (index < vector->size) {
        return vector->data[index];
    }

    return NULL;
}

vector_t * vector_create(void)
{
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    if (vector) {
        memset(vector, 0, sizeof(*vector));
    }

    return vector;
}

void vector_destroy(vector_t *vector)
{
    free(vector->data);
    free(vector);
}

unsigned int vector_size(const vector_t *vector)
{
    return vector->size;
}

unsigned int vector_capacity(const vector_t *vector)
{
    return vector->capacity;
}

void * vector_at(const vector_t *vector, unsigned int index)
{
    return vector_at_(vector, index);
}

void * vector_front(const vector_t *vector)
{
    return vector_at_(vector, 0);
}

void * vector_back(const vector_t *vector)
{
    return vector_at_(vector, vector->size - 1);
}

void ** vector_begin(const vector_t *vector)
{
    return vector->data;
}

void ** vector_end(const vector_t *vector)
{
    return vector->data + vector->size;
}

int vector_push_back(vector_t *vector, const void *data)
{
    if (vector->size >= vector->capacity) {
        const unsigned int new_capacity = (vector->capacity)?  (vector->capacity << 1) : 1;
        const size_t data_size = sizeof(void *) * new_capacity;

        if (vector->data) {
            void **new_data = (void **)realloc(vector->data, data_size);

            if (!new_data) {
                return -1;
            }

            vector->data = new_data;
        }
        else {
            vector->data = (void **)malloc(data_size);

            if (!vector->data) {
                return -1;
            }
        }

        vector->capacity = new_capacity;
    }

    vector->data[vector->size++] = (void *)data;

    return 0;
}

int vector_pop_back(vector_t *vector)
{
    if (!vector->size) {
        return -1;
    }

    vector->data[--vector->size] = NULL;

    return 0;
}

void * vector_find(const vector_t *vector, const void *data)
{
    void **iterator;
    void **end;

    vector_for_each(iterator, end, vector) {
        if (data == *iterator) {
            return *iterator;
        }
    }

    return NULL;
}

void * vector_find_if(const vector_t *vector,
                      const void *data,
                      int (*compare)(const void *element, const void *data))
{
    if (!compare) {
        return NULL;
    }

    void **iterator;
    void **end;

    vector_for_each(iterator, end, vector) {
        if (!compare(*iterator, data)) {
            return *iterator;
        }
    }

    return NULL;
}