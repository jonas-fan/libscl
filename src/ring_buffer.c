#include <ring_buffer.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MIN(lhs, rhs) ((lhs) < (rhs)?  (lhs) : (rhs))

struct ringbuffer_t
{
    unsigned int size;
    unsigned char *buffer;
    unsigned int in;
    unsigned int out;
    pthread_mutex_t mutex;
};

static inline unsigned int roundup_pow_of_two(unsigned int number)
{
    if (!number) {
        return 0;
    }

    --number;

    unsigned int shift = 0;

    while (number) {
        number >>= 1;
        ++shift;
    }

    return (1 << shift);
}

ringbuffer_t * ringbuffer_create(unsigned int size)
{
    if (size & (size - 1)) {
        size = roundup_pow_of_two(size);
    }

    if (size < 2) {
        return NULL;
    }

    ringbuffer_t *ring_buffer = (ringbuffer_t *)malloc(sizeof(ringbuffer_t) + size);

    if (ring_buffer) {
        memset(ring_buffer, 0, sizeof(ringbuffer_t));

        ring_buffer->size = size;
        ring_buffer->buffer = (uint8_t *)ring_buffer + sizeof(ringbuffer_t);

        pthread_mutex_init(&(ring_buffer->mutex), NULL);
    }

    return ring_buffer;
}

void ringbuffer_destroy(ringbuffer_t *ring_buffer)
{
    pthread_mutex_destroy(&(ring_buffer->mutex));

    free(ring_buffer);
}

int ringbuffer_push(ringbuffer_t *ring_buffer, void *data, unsigned int data_size)
{
    pthread_mutex_lock(&(ring_buffer->mutex));

    data_size = MIN(data_size, ring_buffer->size - ring_buffer->in + ring_buffer->out);

    const unsigned int length = MIN(data_size, ring_buffer->size - (ring_buffer->in & (ring_buffer->size - 1)));

    memcpy(ring_buffer->buffer + (ring_buffer->in & (ring_buffer->size - 1)), data, length);

    if (data_size > length) {
        memcpy(ring_buffer->buffer, (uint8_t *)data + length, data_size - length);
    }

    ring_buffer->in += data_size;

    pthread_mutex_unlock(&(ring_buffer->mutex));

    return data_size;
}

int ringbuffer_pop(ringbuffer_t *ring_buffer, void *data, unsigned int data_size)
{
    pthread_mutex_lock(&(ring_buffer->mutex));

    data_size = MIN(data_size, ring_buffer->in - ring_buffer->out);

    const unsigned int length = MIN(data_size, ring_buffer->size - (ring_buffer->out & (ring_buffer->size - 1)));

    memcpy(data, ring_buffer->buffer + (ring_buffer->out & (ring_buffer->size - 1)), length);

    if (data_size > length) {
        memcpy((uint8_t *)data + length, ring_buffer->buffer, data_size - length);
    }

    ring_buffer->out += data_size;

    pthread_mutex_unlock(&(ring_buffer->mutex));

    return data_size;
}