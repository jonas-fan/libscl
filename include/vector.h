#ifndef C_SIMPLE_STL_VECTOR_H_
#define C_SIMPLE_STL_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Simple Vector
 *
 *    @version 0.0.3
 *    @date    2014/06/17
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

void vector_sort(Vector *vector, int (*compare)(const void *, const void *));

#ifdef __cplusplus
}
#endif

#endif  /* C_SIMPLE_STL_VECTOR_H_ */