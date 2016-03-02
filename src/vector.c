#include <vector.h>

#include <stdlib.h>
#include <string.h>

struct vector_t
{
    unsigned char *data;
    unsigned int data_size;
    unsigned int size;
    unsigned int capacity;
};

static inline int vector_at_(const vector_t *vector, unsigned int index, void *data)
{
    if (index >= vector->size) {
        return -1;
    }

    memcpy(data, vector->data + (index * vector->data_size), vector->data_size);

    return 0;
}

vector_t * vector_create(unsigned int data_size)
{
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    if (vector) {
        memset(vector, 0, sizeof(vector_t));

        vector->data_size = data_size;
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

int vector_at(const vector_t *vector, unsigned int index, void *data)
{
    return vector_at_(vector, index, data);
}

int vector_front(const vector_t *vector, void *data)
{
    return vector_at_(vector, 0, data);
}

int vector_back(const vector_t *vector, void *data)
{
    return vector_at_(vector, vector->size - 1, data);
}

int vector_push_back(vector_t *vector, const void *data)
{
    if (vector->size >= vector->capacity) {
        const unsigned int new_capacity = (vector->capacity)?  (vector->capacity << 1) : 1;
        const size_t total_size = vector->data_size * new_capacity;

        if (vector->data) {
            unsigned char *new_data = (unsigned char *)realloc(vector->data, total_size);

            if (!new_data) {
                return -1;
            }

            vector->data = new_data;
        }
        else {
            vector->data = (unsigned char *)malloc(total_size);

            if (!vector->data) {
                return -1;
            }
        }

        vector->capacity = new_capacity;
    }

    memcpy(vector->data + (vector->size * vector->data_size), data, vector->data_size);

    ++vector->size;

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

int vector_find(const vector_t *vector, const void *data)
{
    unsigned char *iterator = vector->data;

    for (unsigned int index = 0; index < vector->size; ++index) {
        if (!memcmp(iterator, data, vector->data_size)) {
            return (int)index;
        }

        iterator += vector->data_size;
    }

    return -1;
}

int vector_find_if(const vector_t *vector,
                   const void *search,
                   unsigned int search_size,
                   int (*compare)(const void *data, unsigned int data_size, const void *search, unsigned int search_size))
{
    if (!compare) {
        return -1;
    }

    unsigned char *iterator = vector->data;

    for (unsigned int index = 0; index < vector->size; ++index) {
        if (!compare(iterator, vector->data_size, search, search_size)) {
            return (int)index;
        }

        iterator += vector->data_size;
    }

    return -1;
}

void vector_for_each(vector_t *vector,
                     void (*callback)(unsigned int index, void *data, unsigned int data_size, void *user_data),
                     void *user_data)
{
    if (!callback) {
        return;
    }

    unsigned char *iterator = vector->data;

    for (unsigned int index = 0; index < vector->size; ++index) {
        callback(index, iterator, vector->data_size, user_data);

        iterator += vector->data_size;
    }
}