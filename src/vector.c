#include <vector.h>

#include <stdlib.h>
#include <string.h>

struct vector_t
{
    void **data;
    unsigned int size;
    unsigned int capacity;
};

static inline int vector_resize_(vector_t *vector, unsigned int size)
{
    if (vector->data) {
        void **new_data = (void **)realloc(vector->data, size);

        if (!new_data) {
            return -1;
        }

        vector->data = new_data;
    }
    else {
        vector->data = (void **)malloc(size);

        if (!vector->data) {
            return -1;
        }
    }

    return 0;
}

static inline void * vector_at_(vector_t *vector, unsigned int index)
{
    if (index >= vector->size) {
        return NULL;
    }

    return vector->data[index];
}

vector_t * vector_create(void)
{
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    if (vector) {
        memset(vector, 0, sizeof(vector_t));
    }

    return vector;
}

void vector_destroy(vector_t *vector)
{
    free(vector->data);
    free(vector);
}

bool vector_empty(vector_t *vector)
{
    return !vector->size;
}

unsigned int vector_size(vector_t *vector)
{
    return vector->size;
}

unsigned int vector_capacity(vector_t *vector)
{
    return vector->capacity;
}

void * vector_at(vector_t *vector, unsigned int index)
{
    return vector_at_(vector, index);
}

void * vector_front(vector_t *vector)
{
    return vector_at_(vector, 0);
}

void * vector_back(vector_t *vector)
{
    return vector_at_(vector, vector->size - 1);
}

int vector_push_front(vector_t *vector, const void *data)
{
    if (vector->size >= vector->capacity) {
        const unsigned int new_capacity = (vector->capacity)?  (vector->capacity << 1) : 1;
        const size_t new_total_size = sizeof(void *) * new_capacity;

        if (vector_resize_(vector, new_total_size) < 0) {
            return -1;
        }

        vector->capacity = new_capacity;
    }

    for (unsigned int index = vector->size; index; --index) {
        vector->data[index] = vector->data[index - 1];
    }

    vector->data[0] = (void *)data;

    ++vector->size;

    return 0;
}

int vector_pop_front(vector_t *vector)
{
    if (!vector->size) {
        return -1;
    }

    for (unsigned int index = 0; index < vector->size - 1; ++index) {
        vector->data[index] = vector->data[index + 1];
    }

    --vector->size;

    return 0;
}

int vector_push_back(vector_t *vector, const void *data)
{
    if (vector->size >= vector->capacity) {
        const unsigned int new_capacity = (vector->capacity)?  (vector->capacity << 1) : 1;
        const size_t new_total_size = sizeof(void *) * new_capacity;

        if (vector_resize_(vector, new_total_size) < 0) {
            return -1;
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

    --vector->size;

    return 0;
}

int vector_find(vector_t *vector, const void *search)
{
    for (unsigned int index = 0; index < vector->size; ++index) {
        if (vector->data[index] == search) {
            return (int)index;
        }
    }

    return -1;
}

int vector_find_if(vector_t *vector,
                   const void *search,
                   int (*compare)(const void *data, const void *search, void *user_data),
                   void *user_data)
{
    if (!compare) {
        return -1;
    }

    for (unsigned int index = 0; index < vector->size; ++index) {
        if (!compare(vector->data[index], search, user_data)) {
            return (int)index;
        }
    }

    return -1;
}

void vector_for_each(vector_t *vector,
                     void (*callback)(unsigned int index, const void *data, void *user_data),
                     void *user_data)
{
    if (!callback) {
        return;
    }

    for (unsigned int index = 0; index < vector->size; ++index) {
        callback(index, vector->data[index], user_data);
    }
}