#include <ring_buffer.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MIN(lhs, rhs) ((lhs) < (rhs)?  (lhs) : (rhs))

struct ringbuffer_t
{
    unsigned int size;
    unsigned char *buffer;
    unsigned int in;
    unsigned int out;
};

static inline unsigned int roundup_pow_of_two(unsigned int number)
{
    if (!number) {
        return 0;
    }

    --number;

    unsigned int retval = 1;

    while (number) {
        number >>= 1;
        retval <<= 1;
    }

    return retval;
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
    }

    return ring_buffer;
}

void ringbuffer_destroy(ringbuffer_t *ring_buffer)
{
    free(ring_buffer);
}

int ringbuffer_push(ringbuffer_t *ring_buffer, void *data, unsigned int data_size)
{
    const unsigned int available_size = ring_buffer->size - ring_buffer->in + ring_buffer->out;

    data_size = MIN(data_size, available_size);

    const unsigned int in_offset = ring_buffer->in & (ring_buffer->size - 1);
    const unsigned int copy_length = MIN(data_size, ring_buffer->size - in_offset);

    memcpy(ring_buffer->buffer + in_offset, data, copy_length);

    if (data_size > copy_length) {
        memcpy(ring_buffer->buffer, (uint8_t *)data + copy_length, data_size - copy_length);
    }

    ring_buffer->in += data_size;

    return data_size;
}

int ringbuffer_pop(ringbuffer_t *ring_buffer, void *data, unsigned int data_size)
{
    const unsigned int used_size = ring_buffer->in - ring_buffer->out;

    data_size = MIN(data_size, used_size);

    const unsigned int out_offset = ring_buffer->out & (ring_buffer->size - 1);
    const unsigned int copy_length = MIN(data_size, ring_buffer->size - out_offset);

    memcpy(data, ring_buffer->buffer + out_offset, copy_length);

    if (data_size > copy_length) {
        memcpy((uint8_t *)data + copy_length, ring_buffer->buffer, data_size - copy_length);
    }

    ring_buffer->out += data_size;

    return data_size;
}