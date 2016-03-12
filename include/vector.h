#ifndef SCL_VECTOR_H_
#define SCL_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Vector
 *
 *    @date    2016/03/12
 *    @author  Jian <jianfan.tw@gmail.com>
 */

#include <stdbool.h>

typedef struct vector_t vector_t;

vector_t * vector_create(void);
void vector_destroy(vector_t *vector);

bool vector_empty(vector_t *vector);
unsigned int vector_size(vector_t *vector);
unsigned int vector_capacity(vector_t *vector);

void * vector_at(vector_t *vector, unsigned int index);
void * vector_front(vector_t *vector);
void * vector_back(vector_t *vector);

int vector_push_front(vector_t *vector, const void *data);
int vector_pop_front(vector_t *vector);
int vector_push_back(vector_t *vector, const void *data);
int vector_pop_back(vector_t *vector);

int vector_find(vector_t *vector, const void *search);
int vector_find_if(vector_t *vector,
                   const void *search,
                   int (*compare)(const void *data, const void *search, void *user_data),
                   void *user_data);

void vector_for_each(vector_t *vector,
                     void (*callback)(unsigned int index, const void *data, void *user_data),
                     void *user_data);

#ifdef __cplusplus
}
#endif

#endif  /* SCL_VECTOR_H_ */