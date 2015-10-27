#ifndef SIMPLE_CONTAINER_RING_BUFFER_
#define SIMPLE_CONTAINER_RING_BUFFER_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ringbuffer_t ringbuffer_t;

ringbuffer_t * ringbuffer_create(unsigned int size);
void ringbuffer_destroy(ringbuffer_t *ring_buffer);

int ringbuffer_push(ringbuffer_t *ring_buffer, void *data, unsigned int data_size);
int ringbuffer_pop(ringbuffer_t *ring_buffer, void *data, unsigned int data_size);

#ifdef __cplusplus
}
#endif

#endif  // SIMPLE_CONTAINER_RING_BUFFER_