#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>

/**
 *    Simple Vector
 *
 *    @version 0.0.1
 *    @date    2014/06/08
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct
{
    void **data;
    unsigned int size;
    unsigned int capacity;
} Vector;

Vector * vector_create();
void vector_destroy(Vector *vector);

unsigned int vector_size(const Vector *vector);
unsigned int vector_capacity(const Vector *vector);

void * vector_at(const Vector *vector, unsigned int index);
void * vector_front(const Vector *vector);
void * vector_back(const Vector *vector);
void ** vector_begin(Vector *vector);
void ** vector_end(Vector *vector);

void vector_push_back(Vector *vector, void *element);
void vector_pop_back(Vector *vector);

#endif  // VECTOR_H_