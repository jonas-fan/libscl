#ifndef __LIBSIMPLECNTR_VECTOR_H__
#define __LIBSIMPLECNTR_VECTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

struct vector_entry
{
    void *data;
};

struct vector
{
    struct vector_entry *entries;
    unsigned int size;
    unsigned int capacity;
};

/* initialize the vector */
void vector_init(struct vector *vector);

/* finalize the vector */
void vector_term(struct vector *vector);

/* return the size of the vector */
unsigned int vector_size(struct vector *vector);

/* check to see if the vector is empty */
int vector_empty(struct vector *vector);

/* return the element at the index in the vector */
void * vector_at(struct vector *vector, unsigned int index);

/* return the first entry of the vector */
struct vector_entry * vector_front(struct vector *vector);

/* return the last entry of the vector */
struct vector_entry * vector_back(struct vector *vector);

/* add an element at the end of the vector, return 1 on success, 0 otherwise */
int vector_push_back(struct vector *vector, const void *data);

/* remove the last entry of the vector */
void vector_pop_back(struct vector *vector);

/* traverse the vector */
#define vector_for_each(vector, entry) \
    for (entry = vector_front(vector); \
         entry; \
         entry = (entry != vector_back(vector)) ? (entry + 1) : NULL)

/* traverse the vector in reverse order */
#define vector_for_each_reverse(vector, entry) \
    for (entry = vector_back(vector); \
         entry; \
         entry = (entry != vector_front(vector)) ? (entry - 1) : NULL)

////////

// struct vector * vector_create(void);
// void vector_destroy(struct vector *vector);

// unsigned int vector_size(struct vector *vector);
// unsigned int vector_capacity(struct vector *vector);

// int vector_insert(struct vector *vector, unsigned int index, const void *data);
// int vector_erase(struct vector *vector, unsigned int index);

// int vector_push_front(struct vector *vector, const void *data);
// int vector_pop_front(struct vector *vector);
// int vector_push_back(struct vector *vector, const void *data);

// void vector_for_each(struct vector *vector,
//                      void (*callback)(unsigned int index, const void *data, void *user_data),
//                      void *user_data);

// void vector_for_each_reverse(struct vector *vector,
//                              void (*callback)(unsigned int index, const void *data, void *user_data),
//                              void *user_data);

// void vector_reverse(struct vector *vector);

// int vector_find(struct vector *vector, const void *search);
// int vector_find_if(struct vector *vector,
//                    const void *search,
//                    int (*compare)(const void *data, const void *search, void *user_data),
//                    void *user_data);

#ifdef __cplusplus
}
#endif

#endif /* __LIBSIMPLECNTR_VECTOR_H__ */