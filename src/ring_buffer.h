#ifndef __LIBSCL_RING_BUFFER_H__
#define __LIBSCL_RING_BUFFER_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ringbuffer_t ringbuffer_t;

// Known issue: The size must be the pow of two.
ringbuffer_t * ringbuffer_create(unsigned int size);
void ringbuffer_destroy(ringbuffer_t *ring_buffer);

int ringbuffer_push(ringbuffer_t *ring_buffer, void *data, unsigned int data_size);
int ringbuffer_pop(ringbuffer_t *ring_buffer, void *data, unsigned int data_size);

#ifdef __cplusplus
}
#endif

#endif  // __LIBSCL_RING_BUFFER_H__