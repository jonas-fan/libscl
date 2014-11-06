#ifndef C_SIMPLE_STL_VECTOR_H_
#define C_SIMPLE_STL_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 *    Simple Vector
 *
 *    @version 0.1.1
 *    @date    2014/11/06
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct vector_t Vector;

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

void * vector_find(const Vector *vector, void *item);
void * vector_find_if(const Vector *vector, void *item, bool (*predicate)(void *item, void *element));

#ifdef __cplusplus
}
#endif

#endif  /* C_SIMPLE_STL_VECTOR_H_ */