#ifndef SCL_VECTOR_H_
#define SCL_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *    Vector
 *
 *    @date    2016/03/02
 *    @author  Jian <jianfan.tw@gmail.com>
 */

typedef struct vector_t vector_t;

vector_t * vector_create(unsigned int data_size);
void vector_destroy(vector_t *vector);

unsigned int vector_size(const vector_t *vector);
unsigned int vector_capacity(const vector_t *vector);

int vector_at(const vector_t *vector, unsigned int index, void *data);
int vector_front(const vector_t *vector, void *data);
int vector_back(const vector_t *vector, void *data);

int vector_push_back(vector_t *vector, const void *data);
int vector_pop_back(vector_t *vector);

int vector_find(const vector_t *vector, const void *data);
int vector_find_if(const vector_t *vector,
                   const void *search,
                   unsigned int search_size,
                   int (*compare)(const void *data, unsigned int data_size, const void *search, unsigned int search_size));

void vector_for_each(vector_t *vector,
                     void (*callback)(unsigned int index, void *data, unsigned int data_size, void *user_data),
                     void *user_data);

#ifdef __cplusplus
}
#endif

#endif  /* SCL_VECTOR_H_ */