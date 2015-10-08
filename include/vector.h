#ifndef SIMPLE_CONTAINER_VECTOR_H_
#define SIMPLE_CONTAINER_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Vector
 *
 *    @date    2015/10/07
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct vector_t vector_t;

vector_t * vector_create(void);
void vector_destroy(vector_t *vector);

unsigned int vector_size(const vector_t *vector);
unsigned int vector_capacity(const vector_t *vector);

void * vector_at(const vector_t *vector, unsigned int index);
void * vector_front(const vector_t *vector);
void * vector_back(const vector_t *vector);
void ** vector_begin(const vector_t *vector);
void ** vector_end(const vector_t *vector);

int vector_push_back(vector_t *vector, const void *data);
int vector_pop_back(vector_t *vector);

void * vector_find(const vector_t *vector, const void *data);
void * vector_find_if(const vector_t *vector,
                      const void *data,
                      int (*compare)(const void *element, const void *data));

#define vector_for_each(iterator, end, vector) \
    for (iterator = vector_begin(vector), end = vector_end(vector); iterator != end; ++iterator)

#ifdef __cplusplus
}
#endif

#endif  /* SIMPLE_CONTAINER_VECTOR_H_ */