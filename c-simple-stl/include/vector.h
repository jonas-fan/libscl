#ifndef SIMPLE_VECTOR_H_
#define SIMPLE_VECTOR_H_

#include <stdlib.h>

/**
 *    Simple Vector
 *
 *    @version 0.0.2
 *    @date    2014/06/17
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct vector_t
{
    void **data;
    unsigned int size;
    unsigned int capacity;
} Vector;

Vector * vector_create(void);
void vector_destroy(Vector *vector);

unsigned int vector_size(const Vector *vector);
unsigned int vector_capacity(const Vector *vector);

void * vector_at(const Vector *vector, unsigned int index);
void * vector_front(const Vector *vector);
void * vector_back(const Vector *vector);
void ** vector_begin(const Vector *vector);
void ** vector_end(const Vector *vector);

void vector_push_back(Vector *vector, void *element);
void vector_pop_back(Vector *vector);

void vector_sort(Vector *vector, int (*compare)(const void *, const void *));

#endif  // SIMPLE_VECTOR_H_