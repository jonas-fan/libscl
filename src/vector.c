#include "vector.h"

#include <stdlib.h>
#include <string.h>

void vector_init(struct vector *vector)
{
    memset(vector, 0, sizeof(struct vector));
}

void vector_term(struct vector *vector)
{
    if (vector && vector->entries) {
        free(vector->entries);
    }

    memset(vector, 0, sizeof(struct vector));
}

unsigned int vector_size(struct vector *vector)
{
    return vector->size;
}

int vector_empty(struct vector *vector)
{
    return (vector_size(vector) == 0);
}

static inline struct vector_entry * __vector_at(struct vector *vector,
    unsigned int index)
{
    return (index < vector->size) ? (vector->entries + index) : NULL;
}

void * vector_at(struct vector *vector, unsigned int index)
{
    struct vector_entry *entry = __vector_at(vector, index);

    return entry ? entry->data : NULL;
}

struct vector_entry * vector_front(struct vector *vector)
{
    return __vector_at(vector, 0);
}

struct vector_entry * vector_back(struct vector *vector)
{
    return __vector_at(vector, vector->size - 1);
}

static inline int __vector_resize(struct vector *vector, unsigned int capacity)
{
    const size_t entries_size = sizeof(struct vector_entry *) * capacity;
    struct vector_entry *entries = NULL;

    if (vector->entries) {
        entries = (struct vector_entry *)realloc(vector->entries, entries_size);
    }
    else {
        entries = (struct vector_entry *)malloc(entries_size);
    }

    if (!entries) {
        return 0;
    }

    vector->entries = entries;
    vector->size = (vector->size < capacity) ? vector->size : capacity;
    vector->capacity = capacity;

    return 1;
}

static inline int __vector_enlarge(struct vector *vector)
{
    const unsigned int capacity = vector->capacity ? (vector->capacity << 1) : 1;

    return __vector_resize(vector, capacity);
}

int vector_push_back(struct vector *vector, const void *data)
{
    if (vector->size >= vector->capacity) {
        if (!__vector_enlarge(vector)) {
            return 0;
        }
    }

    vector->entries[vector->size++].data = (void *)data;

    return 1;
}

void vector_pop_back(struct vector *vector)
{
    if (!vector_empty(vector)) {
        --vector->size;
    }
}